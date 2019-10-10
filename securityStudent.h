/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: securityStudent.h
 * Author: Sean Robinson 
 * Class: C867 Scripting & Programming - Applications
 * Mentor: Tom Grant 
 */

#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"

class SecurityStudent : public Student {                    // inheriting Student public functions/variables
	public: 
		virtual Degree getDegreeProgram();
		using Student::Student;                     // lifting student properties to SecurityStudent
	private:
		Degree DegreeType = SECURITY;               // this WILL be a Security student!
};



#endif /* SECURITYSTUDENT_H */

