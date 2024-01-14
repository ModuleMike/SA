#include "student.h"
#include "degree.h"
#include <iostream>


// (D.1) - Default constructor for initializing variables to default values.

Student::Student() :
	student_ID(""),
	first_Name(""),
	last_Name(""),
	email_Address(""),
	student_Age(0),
	first_Course_Day_Count(0),
	second_Course_Day_Count(0),
	third_Course_Day_Count(0),
	day_Counts_Array{ 0, 0, 0 },
	degree_Program(NA)
{

}

// (D.2.D) - Constructor with paramaters for initializing variable values.

Student::Student(
	std::string student_ID,
	std::string first_Name,
	std::string last_Name,
	std::string email_Address,
	int student_Age,
	int first_Course_Day_Count,
	int second_Course_Day_Count,
	int third_Course_Day_Count,
	DegreeProgram degree_Program
)
{

	this->student_ID = student_ID;
	this->first_Name = first_Name;
	this->last_Name = last_Name;
	this->email_Address = email_Address;
	this->student_Age = student_Age;
	this->first_Course_Day_Count = first_Course_Day_Count;
	this->second_Course_Day_Count = second_Course_Day_Count;
	this->third_Course_Day_Count = third_Course_Day_Count;
	this->day_Counts_Array[0] = first_Course_Day_Count;
	this->day_Counts_Array[1] = second_Course_Day_Count;
	this->day_Counts_Array[2] = third_Course_Day_Count;
	this->degree_Program = degree_Program;
}

// Destructor for the Student class.

Student::~Student() { }


// (D.2.E) - Prints student related data using accessors.

void Student::print()
{

	std::cout << this->access_Student_ID() << '\t';
	std::cout << "First Name: " << this->access_First_Name() << '\t';
	std::cout << "Last Name: " << this->access_Last_Name() << '\t';
	std::cout << "Age: " << this->access_Student_Age() << " " << '\t';

	std::cout << "daysInCourse: " << "{" << this->access_Day_Counts_Array()[0] << ", "
		<< this->access_Day_Counts_Array()[1] << ", "
		<< this->access_Day_Counts_Array()[2] << "}" << '\t';

	std::cout << "Degree Program: " << access_Program_Name[this->access_Degree_Program()] << "\n";

	std::cout << "\n";

}


/**
*
* (D.2.A) - Section for Accessor's
*
**/


// (D.2.A) - Accessor for student ID.

std::string Student::access_Student_ID()
{
	return this->student_ID;
};


// (D.2.A) - Accessor for first name.

std::string Student::access_First_Name()
{
	return this->first_Name;
};


// (D.2.A) - Accessor for last name.

std::string Student::access_Last_Name()
{
	return this->last_Name;
};


// (D.2.A) - Accessor for email address.

std::string Student::access_Email_Address()
{
	return this->email_Address;
};


// (D.2.A) - Accessor for student age.

int Student::access_Student_Age()
{
	return this->student_Age;
};


// (D.2.A) - Accessor for student course day counts array.

int* Student::access_Day_Counts_Array()
{
	return this->day_Counts_Array;
};


// (D.2.A) - Accessor for degree program.

DegreeProgram Student::access_Degree_Program()
{
	return this->degree_Program;
};


/**
*
* (D.2.B) - Section for Mutator's
*
**/


// (D.2.B) - Mutator for student ID.

void Student::mutate_Student_ID(std::string student_ID)
{
	this->student_ID = student_ID;
};


// (D.2.B) - Mutator for first name.

void Student::mutate_First_Name(std::string first_Name)
{
	this->first_Name = first_Name;
};


// (D.2.B) - Mutator for last name.

void Student::mutate_Last_Name(std::string last_Name)
{
	this->last_Name = last_Name;
};


// (D.2.B) - Mutator for email address.

void Student::mutate_Email_Address(std::string email_Address)
{
	this->email_Address = email_Address;
};


// (D.2.B) - Mutator for student age.

void Student::mutate_Student_Age(int student_Age)
{
	this->student_Age = student_Age;
};


// (D.2.B) - Mutator for student course day counts array.

void Student::mutate_Day_Counts_Array(int first_Course_Day_Count, int second_Course_Day_Count, int third_Course_Day_Count)
{
	this->day_Counts_Array[0] = first_Course_Day_Count;
	this->day_Counts_Array[1] = second_Course_Day_Count;
	this->day_Counts_Array[2] = third_Course_Day_Count;
}


// (D.2.B) - Mutator for degree program.

void Student::mutate_Degree_Program(DegreeProgram degree_Program)
{
	this->degree_Program = degree_Program;
};