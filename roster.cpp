/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: roster.cpp 
 * Author: Sean Robinson 
 * Class: C867 Scripting & Programming - Applications
 * Mentor: Tom Grant 
 */
#include <iostream>
#include <sstream>
#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using namespace std;

const static int STR_SIZE = 9;
const static int NUM_STUDENTS = 5;

Roster::Roster(){
    
}
Roster::~Roster(){
    //cout << "\ndestructor called...." << endl;
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram){
    int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	
    for (int i = 0; i < NUM_STUDENTS; i++) {
	if (classRosterArray[i] == nullptr) {
            if (degreeProgram == NETWORKING) {
                classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, email, age, days, degreeProgram);
            }
            else if (degreeProgram == SECURITY) {
                classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, email, age, days, degreeProgram);
            }
            else if (degreeProgram == SOFTWARE) {
                classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, email, age, days, degreeProgram);
            }
            else {
                cout << "Unknown Student Degree" << endl;
            }
            break;                          //stop processing
        }
    }
}

void Roster::printAll(){
    for(int i = 0; i < NUM_STUDENTS; ++i){
        classRosterArray[i]->print();
    }
    cout << endl;
}

void Roster::remove(string studentID) {
    bool entryRemoved = false;                  //initialize 
    for(int i = 0; i < NUM_STUDENTS; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID){   //does the entry exist and is there an entry that matches?
            entryRemoved = false;
            cout << "Student ID found. Attempting to remove entry...." << endl;
            classRosterArray[i] = nullptr;
            cout << "Entry removed." << endl;
            entryRemoved = true;
            break;
        }
        else if (entryRemoved == false && i == 4) {             //Prints that the entry was not found and keeps it from repeating itself
            cout << "ERROR: This student ID was not found." << endl;
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID){
    cout << "Looking for student with ID: " << studentID << "... ";
    for (int i = 0; i < NUM_STUDENTS; ++i){
        if (classRosterArray[i] != nullptr){                //check to make sure the entry exists
            string str = classRosterArray[i]->getStudentID();
            int *daysArray = classRosterArray[i]->getDaysToComplete();
            int days1 = daysArray[0];
            int days2 = daysArray[1];
            int days3 = daysArray[2];
            int avgDays = (days1 + days2 + days3) / 3;
            if(str == studentID){
                cout << "Student found." << endl;
                cout << "\tThe average amount of days in the courses are: " << avgDays << "\n" << endl;
            }
        } else {                                           //output if the entry does not exist
            cout << "Entry does not exist.\n" << endl;
            break;
        }
    }
}

void Roster::printInvalidEmails(){
    cout << "Printing invalid Email addresses......\n" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        bool at = false;
        bool period = false;
        bool space = false;
    
        if(classRosterArray[i] != nullptr){
            string str = classRosterArray[i]->getEmail();
            for (int i = 0; i < str.size(); i++){
                //cout << str[i];
                if (str[i] == '@') {
                     at = true;
                 //    cout << "at symbol has been found" << endl;
                }
                if (str[i] == '.'){
                     period = true;
                //     cout << "Period has been found" << endl;
                }
                if (str[i] == ' '){
                     space = true;
                //     cout << "Error: space found." << endl;
                }
            }
            //if (at == true && period == true && space != true){
            //cout << "Email is valid." << endl;
            //}
            if (at == false || period == false || space == true){
            cout << str <<endl;
            }
        }   
    }
    cout << endl;
}

void Roster::printByDegreeProgram(int degreeProgram){
    cout << "Searching for students by degree: " << endl;
    
    for (int i = 0; i < NUM_STUDENTS; ++i){
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegree() == degreeProgram){
            classRosterArray[i]->print();
        }
    }
}

int main() {
  
    const string studentData[NUM_STUDENTS] =
    {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Sean,Robinson,irobbierobinson@gmail.com,30,30,30,30,SOFTWARE"};
    
    Roster classRoster;                                //create new roster
    Degree studDegree;                                   //create degree
    //Student Georgie;                                     //test student
    
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 000922432" << endl;
    cout << "Student: Sean Robinson" << endl;
    cout << "Mentor: Tom Grant\n" << endl;
    
    for (int i = 0; i < NUM_STUDENTS; ++i){              //Time to parse student data
        char split_char = ',';                           //character initialized for parse function with istringstream
        vector<string> tokens;                           //tokens variable to be used with parsing function
        
        istringstream split(studentData[i]);
        for (string each; getline(split, each, split_char); tokens.push_back(each));
        
        string id, first, last, email;
        int age,course1,course2,course3;
        
        /*
         * for (int i = 0; i < STR_SIZE; ++i){              // outputting tokens to view from console
         * cout << tokens[i] << "\t";
         * }
        */
        
        id = tokens[0];                                  //creating local variable to store parsed information
        first = tokens[1];
        last = tokens[2];
        email = tokens[3];
        age = stoi(tokens[4]);
        course1 = stoi(tokens[5]);
        course2 = stoi(tokens[6]);
        course3 = stoi(tokens[7]);
        
        //cout << "\nToken values assigned to variables " << endl;
           
        if (tokens[8] == "SECURITY") {
            studDegree = SECURITY;
        } else if (tokens[8] == "NETWORK") {
            studDegree = NETWORKING;
        } else if (tokens[8] == "SOFTWARE"){
            studDegree = SOFTWARE;
        } else {
            cout << "Unknown degree?" << endl;
        }
        
        //cout << "Degree assignment successful." << endl;

        classRoster.add(id, first, last, email, age, course1, course2, course3, studDegree);  
        
        //cout << "Student roster information added to array." << "\n" << endl;
    }
        
    classRoster.printAll();
    classRoster.printInvalidEmails();
    //loop through classRosterArray and for each element:
    for (int i = 0; i < NUM_STUDENTS; ++i){             // printing average days for each student
        if(classRoster.classRosterArray[i] != nullptr){
            classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        }
    }
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.remove("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.
    
    classRoster.~Roster();
    return 0;
}
