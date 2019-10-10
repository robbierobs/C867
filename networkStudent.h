/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: networkStudent.h
 * Author: Sean Robinson 
 * Class: C867 Scripting & Programming - Applications
 * Mentor: Tom Grant 
 */

#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"

class NetworkStudent : public Student {             // inheriting Student public functions/variables
	public: 
            virtual Degree getDegreeProgram();
            using Student::Student;                 // Lifts Student class properties
	private:
            Degree DegreeType = NETWORKING;         // Guarantees it will be a Network student!
};

#endif /* NETWORKSTUDENT_H */

