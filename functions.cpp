// file: functions.cpp
// Name: Mia Campanella
// Define the functions, per the list in headers.h
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#include "structs.h"
#include "headers.h"

void NameSort(UndergradStudents array[], int size) {
    // Bubble sort implementation to sort by last name
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Compare last names 
            if (array[j].lastName > array[j+1].lastName) {
                // Swap the entire student record
                UndergradStudents temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void InitializeStructures(UndergradStudents us[], int &size) {
    // Reset size to 0 before starting
    size = 0;
    
    cout << "STUDENT RECORDS:\n";
    
    // Loop to input student information
    while (size < 20) {
        // Increment student number for display
        int studentNum = size + 1;
        
        // Prompt for first name
        string firstName;
        cout << "Student " << setw(2) << setfill('0') << studentNum << ":Enter first name (or x to quit): ";
        cin >> firstName;
        
        // Check for quit condition
        if (firstName == "x" || firstName == "X") {
            break;
        }
        
        // Continue with other inputs
        UndergradStudents& student = us[size];
        
        // Set student ID (1-based index)
        student.studentID = studentNum;
        student.firstName = firstName;
        
        // Get last name
        cout << "Student " << studentNum << ":Enter last name: ";
        cin >> student.lastName;
        
        // Get major
        cout << "Student " << studentNum << ":Enter major: ";
        cin >> student.major;
        
        // Get GPAs for 4 years
        cout << "Student " << studentNum << ":Enter GPA Year 1: ";
        cin >> student.yearOneGPA;
        
        cout << "Student " << studentNum  << ":Enter GPA Year 2: ";
        cin >> student.yearTwoGPA;
        
        cout << "Student " << studentNum << ":Enter GPA Year 3: ";
        cin >> student.yearThreeGPA;
        
        cout << "Student " << studentNum << ":Enter GPA Year 4: ";
        cin >> student.yearFourGPA;
        
        // Increment size
        size++;
    }
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) {
    // Sort the array first
    NameSort(us, size);
    
    // Write header
    outf << "These are the results sorted by last name:\n";
    
    // Write each student's information
    for (int i = 0; i < size; i++) {
        // Calculate average GPA
        float avgGPA = (us[i].yearOneGPA + us[i].yearTwoGPA + us[i].yearThreeGPA + us[i].yearFourGPA) / 4.0;
        
        // Write to file with specific formatting
        outf << "ID# " << us[i].studentID << ": " 
             << us[i].lastName << ": " 
             << us[i].firstName << ": " 
             << us[i].major << ": " 
             << fixed << setprecision(2) << avgGPA << endl;
    }
}



