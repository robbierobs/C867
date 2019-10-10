/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: student.cpp 
 * Author: Sean Robinson 
 * Class: C867 Scripting & Programming - Applications
 * Mentor: Tom Grant 
 */

#include "student.h"
#include <iostream>
#include <string>

using namespace std;

// setters


void Student::setStudentID(string ID){
    studentID = ID;
}
void Student::setStudentAge(int age){
    studentAge = age;
}
void Student::setDaysToComplete(int *courseDays) {
    for (int i = 0; i < 3; i++) {
        days[i] = courseDays[i];        
    }
}
void Student::setFirstName(string name){
    studentFirstName = name;
}
void Student::setLastName(string name){
    studentLastName = name;
}
void Student::setEmail(string email){
    emailAdd = email;
}
void Student::setDegree(Degree deg){
   degreeType = deg;
}

// getters

string Student::getStudentID() const {
    return studentID;
}
int Student::getStudentAge() const {
    return studentAge;
}
int * Student::getDaysToComplete() {
    return days;
}
string Student::getFirstName() const {
    return studentFirstName;
}
string Student::getLastName() const {
    return studentLastName;
}
string Student::getEmail() const {
    return emailAdd;
}
Degree Student::getDegree() {
    return degreeType;
}
Degree Student::getDegreeProgam(){
    return degreeType;
}

// others

void Student::print(){
    int *daysLeft = getDaysToComplete();
    cout << getStudentID() << "\tFirst Name: ";
    cout << getFirstName() << "\tLast Name: ";
    cout << getLastName() << "\tAge: ";
    cout << getStudentAge() << "\t\tDays in course: {";
    cout << daysLeft[0] << ", " << daysLeft[1] << ", " << daysLeft[2] << "}\tDegree Program: ";
    switch (getDegree()) {
        case 0: cout << "Security" << endl;
        break;
        case 1: cout << "Networking" << endl;
        break;
        case 2: cout << "Software" << endl;
        break;
    }
    //cout << endl;         // separating the rows to look for errors
}

// constructor

Student::Student(){
    int days[3] = {0,0,0};
    setStudentAge(-1);
    setStudentID("00");
    setEmail("None");
    setFirstName("Empty");
    setLastName("Empty");
    setDegree(SECURITY);
    setDaysToComplete(days);
    cout << "Default attributes set...";
}


Student::Student(string id, string first, string last, string email, int age, int days[3], Degree degreeType){
    setStudentID(id);
    setFirstName(first);
    setLastName(last);
    setEmail(email);
    setStudentAge(age);
    setDaysToComplete(days);    
    setDegree(degreeType);
}

//destructor

Student::~Student() {
    //cout << "Destructor called..." << endl;
}