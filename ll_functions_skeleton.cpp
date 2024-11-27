// file: ll_functions.cpp
#include "ll_headers.h"

// Used in the function createLL()
// This function is given to you correctly - there is no need to change it
void h_insert(LinkNodePtr& head, string nom, int num) {
    LinkNodePtr tmp_ptr;
    tmp_ptr = new LinkNode;

    tmp_ptr->name = nom;
    tmp_ptr->number = num;
    tmp_ptr->link = head;

    head = tmp_ptr;
}

void createLL(LinkNodePtr& h) {
    // Incomplete function - student must complete
    string nom = "";
    int num;  
    while(0) // THIS IS A STUB
    {
        cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";
        cin >> nom >> num;
        // Incomplete code here...
        // At some point, you call:    h_insert(h, nom, num);
    }
}

void printLL(LinkNodePtr h) {
    // Incomplete function - student must complete
    cout << "printLL\n"; // THIS IS A STUB
}

void insertNodeAfter(LinkNodePtr h) {
    // Incomplete function - student must complete
    cout << "insertNodeAfter\n"; // THIS IS A STUB
}

void findMax(LinkNodePtr h) {
    // Incomplete function - student must complete
    int max(0);
    cout << "Largest number in the list is: " << max << endl;
}

void findMin(LinkNodePtr h) {
    // Incomplete function - student must complete
    int min(0);
    cout << "Smallest number in the list is: " << min << endl;
}

