/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: roster.h
 * Author: Sean Robinson 
 * Class: C867 Scripting & Programming - Applications
 * Mentor: Tom Grant 
 */
#ifndef ROSTER_H
#define ROSTER_H

#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "student.h"
#include "degree.h"

class Roster {
	public: 
            ~Roster();
            Roster();
            void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);  // add   Degree degreeProgram to the end of these parameters
            void printAll();
            void printByDegreeProgram(int degreeProgram);
            void printAverageDaysInCourse(string studentID);
            void printInvalidEmails();
            void remove(string studentID);
            Student *classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr};

};

#endif /* ROSTER_H */

