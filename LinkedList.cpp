//
// Created by MSI on 2019/10/25.
//

#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

//default constructor
LinkedList::LinkedList() {
    head = nullptr;
}

//print the list's values
void LinkedList::printList() const {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->getValue() << endl;
        curr = curr->getNext();
    }
}

//find whether the value exists as a member of the nodes within the linked list
bool LinkedList::isItem(int item) const {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->getValue() == item) {
            return true;
        }
        curr = curr->getNext();
    }
    return false;
}

//append a node to the end of the list FIXME
void LinkedList::append(int item) {
    if (head == nullptr) {
        head = new Node(item, nullptr);
    }
    else {
        Node* curr = head;
        while (curr->getNext() != nullptr) {
            curr = curr->getNext();
        }
        curr->next = new Node(item, nullptr);
    }
}

//remove
bool LinkedList::remove(int item) {
    // empty list, we do not remove anything
    if (head == nullptr) {
        return false;
    }

    Node* curr = head;
    Node* prev;
    // remove first item in the list
    if (head->getValue() == item) {
        head = head->getNext();
        curr->next = nullptr;
        delete curr;
        return true;
    }

    //normal remove, when the item in the list > 1
    while (curr != nullptr) {
        if (curr->getValue() == item) {
            prev->next = curr->getNext();
            curr->next = nullptr;
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->getNext();
    }
    return false;
}

void LinkedList::InsertionSort(Node* start){ //FIXME
    //if the list contain 0 or 1 element, return
    if(this->head == nullptr && head->getNext() == nullptr){
        return;
    }
    //create a temp pointer to go through the list to indicate the node that is currently sorting
    Node *tempNode = this->head->getNext(); //initialize them to point towards the second object in the list (since the first object is not required to sort)

    //go through the list one by one, take the value of the node and be ready to compare with other values in the portion of the list that is sorted
    while(tempNode != nullptr){
        int valueData = tempNode->getValue(); //store the value of the current object's value in a int type variable (act as a temp variable)
        bool foundPosition = false; //use to break out of the loop
        Node *temp1Node = this->head; //start from the first object of the list and compare with the current object indicated by tempNode
        while(temp1Node != tempNode){
            if(temp1Node->getValue() > tempNode->getValue() && foundPosition == false) {
                //insert the node
                valueData = temp1Node->getValue();
                temp1Node->value = tempNode->getValue();
                foundPosition = 1; //break out of the loop
                temp1Node = temp1Node->getNext();
            }
            else{
                if(foundPosition == 1){
                    int tempValue = valueData;
                    valueData = temp1Node->getValue();
                    temp1Node->value = tempValue;
                }
                temp1Node = temp1Node->getNext();
            }
        }
        temp1Node->value = valueData;
        tempNode = tempNode->getNext();
    }
}


LinkedList::LinkedList(LinkedList &copy){ //no returning value
this->head = copy.head;
}

LinkedList& LinkedList::operator=(const LinkedList &assign){ //return *this
this->head = assign.head;
return *this;
}

LinkedList::~LinkedList(){ //no returning value
}

