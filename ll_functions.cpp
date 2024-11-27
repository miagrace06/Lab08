// file: ll_functions.cpp
//Name: Mia Campanella
#include <iostream>
#include <string>
using namespace std;

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
    string nom = "";
    int num = 0;
    //Reset the head pointer to NULL to start fresh
    h = NULL;

    while (true) {
        cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";
        cin >> nom >> num;

        //Check for quit condition
        if (nom == "0" && num == 0) {
            break;
    }
        //Call h_insert to add the node to the front of the list
        h_insert(h, nom, num);
    }
    //If no nodes were added, print the empty list message
    if (h == NULL) {
        cout << "This list is empty." << endl;
    }
}



void printLL(LinkNodePtr h) {
    //Check if list is empty
    if (h == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    int nodeCount = 0;
    LinkNodePtr current = h;

    //Go through the list and print each note 
    cout << "Printing this list: " << endl;
    while (current != NULL) {
        cout << "Node #" << nodeCount << ": " << (*current).name << ", " << (*current).number << endl;
        current = (*current).link;
        nodeCount++;
    }
    cout << "--------" << endl;
}

void insertNodeAfter(LinkNodePtr& h) {
    //Check if the list is empty
    if (h == NULL) {
        cout << "Cannot insert in a non-existing link." << endl;
        return;
    }
    int position;
    cout << "enter node position to insert new node after (enter negative number to exit): ";
    cin >> position;

    //Exit if negative position entered
    if (position < 0) {
        return;
    }

    //Count total number of nodes
    int nodeCount = 0;
    LinkNodePtr current = h;
    while (current != NULL) {
        nodeCount++;
        current = (*current).link; //dereference current to get the next node
    }
    //Check if position is valid
    if (position >= nodeCount) {
        cout << "Position entered is illegal. Nothing inserted." << endl;
        return;
    }
    //Get new node data
    string nom;
    int num;
    cout << "Enter data (name, then number): ";
    cin >> nom >> num;

    //Find the node at the specified position
    current = h;
    for (int i = 0; i < position; i++) {
        current = (*current).link;
    }
    //Create new node
    LinkNodePtr newNode = new LinkNode;
    (*newNode).name = nom;
    (*newNode).number = num;

    //insert the new node
    (*newNode).link = (*current).link; //Make newNode's link point to the next node
    (*current).link = newNode; //Update the current node to point to the new node
        
}

void findMax(LinkNodePtr h) {
    //Check if the list is empty
    if (h == NULL) {
        cout << "This list is empty." << endl;
        return;
    }
    int max = (*h).number; //Dereference h to access the number
    LinkNodePtr current = (*h).link; //Dereference h to access the next node

    //Go through the list to find maximum
    while (current != NULL) {
        if ((*current).number > max) { //Dereference current to access the number
            max = (*current).number;
        }
        current = (*current).link; //Dereference current to move to the next node
    }
    cout << "Largest number in the list is: " << max << endl;
}

void findMin(LinkNodePtr h) {
    //Check if list is empty
    if (h == NULL) {
        cout << "This list is empty." << endl;
        return;
    }
    int min = (*h).number; //Dereference h to access the number
    LinkNodePtr current = (*h).link; //Dereference h to access the next node

    //Go through the list to find minimum
    while (current != NULL) {
        if ((*current).number < min) { //Derference current to access the number
            min = (*current).number;
        }
        current = (*current).link; //Dereference current to move to the next node
    }
    cout << "Smallest number in the list is: " << min << endl;
}

