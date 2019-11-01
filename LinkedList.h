//
// Created by MSI on 2019/10/25.
//

#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H

#endif //BINARYINSERTIONSORT_LINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList{
private:


public:
    LinkedList(); // default constructor
    void printList () const; //printing the list
    bool isItem(int item) const; //
    void append(int item);
    bool remove(int item);
    void InsertionSort(Node* start); //Insertion sort function
    LinkedList(LinkedList &copy); //copy constructor
    LinkedList& operator=(const LinkedList &assign); //copy assignment operator
    ~LinkedList(); //destructor
    Node* head;


};