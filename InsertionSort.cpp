#include <iostream>
#include <vector>
#include "BinaryInsertionSort.h"
#include "Node.h"
#include "LinkedList.h"
#include <cassert>
#include <ctime>
using namespace std;

int main() {

    int seed, length;
    cout << "Please enter a random number for the seed and also the length of the vector / linked list you would like to sort:";
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);

    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100; //the values in the vector v should be 0 to 99
    }

    //insert values to a linked list FIXME
    LinkedList *list = new LinkedList(); //define a new linked list
    for(int i = 0; i < v.size(); i++){
        list->append(v[i]);
    }

    //find the time for execution of insertion sort on vectors
    clock_t start_insertionSort = clock(); // check the clock time before and after executing the function to further calculate the CPU time
    // binary insertion sort
    insertionSort(v, v.size());
    //check the clock time after sorting the vector
    clock_t end_insertionSort = clock();


    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }


    // print out sorted list
    cout << "After insertionSort of vector." << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    // FINISH ME
    //calculate the time for executing the insertion sort for linked list
    clock_t start_InsertionSort = clock();
    //InsertionSort for the linked list
    list->InsertionSort(list->head);
    //check the clock time after sorting the linked list
    clock_t end_InsertionSort = clock();



    //check if sorted

    Node *curr = list->head;
    Node *nextNode = list->head->getNext();
    while(nextNode != nullptr){
        assert(curr->getValue() <= nextNode->getValue());
        curr = curr->getNext();
        nextNode = nextNode->getNext();
    }

    //print out the sorted list
    cout << "after InsertionSort on linked list" << endl;
    list->printList();

    //calculate the execution time of insertion sort on a vector and on a linked list
    double elapsed_insertionSort = double(end_insertionSort - start_insertionSort) / CLOCKS_PER_SEC; // CPU time = Total clock cycles / clock rate
    double elapsed_InsertionSort = double(end_InsertionSort - start_InsertionSort) / CLOCKS_PER_SEC;

    //print out the execution time and compare
    cout << elapsed_insertionSort << " " << elapsed_InsertionSort << endl;



    return 0;




}