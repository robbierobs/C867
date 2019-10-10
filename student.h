/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: student.h 
 * Author: Sean Robinson 
 * Class: C867 Scripting & Programming - Applications
 * Mentor: Tom Grant 
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "degree.h"

using namespace std;

class Student {
public:
    //******************
    //Testing parsing stuff
    //******************
       
    //Fix this stuff
   // void print();
   // void getDegreeProgram();  
    
    //Student Mutators
    void setStudentID(string);
    void setStudentAge(int);
    void setDaysToComplete(int[3]);
    void setFirstName(string);
    void setLastName(string);
    void setEmail(string);
    void setDegree(Degree);
    
    
    //Student Accessors
    int getStudentAge() const;
    int *getDaysToComplete();
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    
    // virtual
    virtual Degree getDegreeProgam();
    virtual Degree getDegree();        
    virtual void print();
    
    Student();      //constructor 
    ~Student();      //destructor
    Student(string, string, string, string, int, int*, Degree);
private:
  
    int studentAge;
    int days[3];
    string studentID;
    string studentFirstName;
    string studentLastName;
    string emailAdd;
    Degree degreeType;

};


#endif /* STUDENT_H */

