/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: softwareStudent.h
 * Author: Sean Robinson 
 * Class: C867 Scripting & Programming - Applications
 * Mentor: Tom Grant 
 */

#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"

class SoftwareStudent : public Student {                        // inheriting Student public functions/variables
	public: 
		virtual Degree getDegreeProgram();
		using Student::Student;                         // lifting Student properties
	private:
		Degree DegreeType = SOFTWARE;                   // They WILL be a Software Student!
};



#endif /* SOFTWARESTUDENT_H */

