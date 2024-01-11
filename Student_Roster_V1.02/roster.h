#pragma once
#include "student.h"
#include "degree.h"


// (E) - Class Roster that manages the collection of students.

class Roster {

private:

	// The static constant for the total number of students in the roster

	const static int total_Students_On_Roster = 5;

public:

	// (E.1) - The class roster array to store pointers to the Student objects.

	Student* classRosterArray[total_Students_On_Roster];


	// Constructor for the Roster class.

	Roster();


	// Destructor for the Roster class.

	~Roster();


	// (E.2.A & B) - Method to parse and add a student from the provided data string.

	void parse_Student_Data(std::string);


	// (E.3.A) - Method to add a new student to the roster.

	void add(std::string, std::string, std::string, std::string, int, int, int, int, DegreeProgram);


	// (E.3.B) - Method to remove a student from the roster by their student ID.

	void remove(std::string studentID);


	// (E.3.C) - Method to print all students and their data from the roster.

	void printAll();


	// (E.3.D) - Method to print the average number of days each student spent in courses.

	void printAverageDaysInCourse(std::string);


	// (E.3.E) - Method to print the invalid email addresses found in the roster.

	void printInvalidEmails();


	// (E.3.F) - Method to the print students with a specific degree program input.

	void printByDegreeProgram(DegreeProgram degreeProgram);

};
