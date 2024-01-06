#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>	


// (E)/(E.1) - Roster class constructor initializing classRosterArray.

Roster::Roster()
{
	for (int index = 0; index < total_Students_On_Roster; index++) {
		classRosterArray[index] = NULL;
	}
}


// Roster class destructor deallocating memory created by classRosterArray.

Roster::~Roster()
{
	for (int index = 0; index < total_Students_On_Roster; index++)
	{
		delete classRosterArray[index];
		classRosterArray[index] = nullptr;
	}
}


// (E.2.A & B) - Method to parse student data from a string and add the student data to the roster.

void Roster::parse_Student_Data(std::string student_Data_Input)
{
	std::string parsed_Segment;
	std::string segment_Array[9];
	int array_Index = 0;
	size_t position = 0;

	while ((position = student_Data_Input.find(',')) != std::string::npos)
	{
		parsed_Segment = student_Data_Input.substr(0, position);
		segment_Array[array_Index++] = parsed_Segment;
		student_Data_Input.erase(0, position + 1);
	}

	segment_Array[array_Index] = student_Data_Input;

	std::string student_ID_Parsed = segment_Array[0];
	std::string first_Name_Parsed = segment_Array[1];
	std::string last_Name_Parsed = segment_Array[2];
	std::string email_Address_Parsed = segment_Array[3];
	int student_Age_Parsed = std::stoi(segment_Array[4]);
	int first_Course_Day_Count_Parsed = std::stoi(segment_Array[5]);
	int second_Course_Day_Count_Parsed = std::stoi(segment_Array[6]);
	int third_Course_Day_Count_Parsed = std::stoi(segment_Array[7]);
	std::string degree_Program_Parsed = segment_Array[8];

	DegreeProgram degree_Program_Enum = NA;

	if
		(degree_Program_Parsed == "SECURITY") degree_Program_Enum = SECURITY;
	else if
		(degree_Program_Parsed == "NETWORK") degree_Program_Enum = NETWORK;
	else if
		(degree_Program_Parsed == "SOFTWARE") degree_Program_Enum = SOFTWARE;


	add(
		student_ID_Parsed,
		first_Name_Parsed,
		last_Name_Parsed,
		email_Address_Parsed,
		student_Age_Parsed,
		first_Course_Day_Count_Parsed,
		second_Course_Day_Count_Parsed,
		third_Course_Day_Count_Parsed,
		degree_Program_Enum
	);
}


// (E.3.A) - Method to add a student to the roster.

void Roster::add
(
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

	bool add_Student_Bool = false;
	int index = 0;

	do {
		if (classRosterArray[index] == NULL) {
			classRosterArray[index] = new Student
			(student_ID, first_Name, last_Name, email_Address, student_Age, first_Course_Day_Count, second_Course_Day_Count, third_Course_Day_Count, degree_Program);
			add_Student_Bool = true;
		}

		index++;

	} while (index < total_Students_On_Roster && add_Student_Bool == false);

	if (!add_Student_Bool)
	{
		std::cout << "Warning! Student was not able to be added to the roster!";
	}
}


// (E.3.B) - Method to remove a student from the roster using a student ID.

void Roster::remove(std::string student_ID_Input)
{
	bool student_ID_Located = false;

	for (int index = 0; index < total_Students_On_Roster; index++)
	{
		if (classRosterArray[index] != nullptr && classRosterArray[index]->access_Student_ID() == student_ID_Input)
		{
			delete classRosterArray[index];
			student_ID_Located = true;
			classRosterArray[index] = nullptr;

			std::cout << "\nThe removal of the student with student ID (" << student_ID_Input << ") was removed successfully.";

			break;
		}
	}
	if (!student_ID_Located)
	{
		std::cout << "\nWarning! -- Student with student ID (" << student_ID_Input << ") was NOT able to be located. -- Warning! \n\n";
	}
}


// (E.3.C) - Method to print all students in the roster.

void Roster::printAll()
{
	for (int index = 0; index < total_Students_On_Roster; index++)
	{
		if (classRosterArray[index] != nullptr)
		{
			classRosterArray[index]->print();
		}
	}
}


// (E.3.D) - Method to print the average days in course for a student by student ID.

void Roster::printAverageDaysInCourse(std::string student_ID_Input) {

	bool student_ID_Located = false;

	for (int index = 0; index < total_Students_On_Roster; index++)
	{
		if (classRosterArray[index] != NULL && classRosterArray[index]->access_Student_ID() == student_ID_Input)
		{

			int course_Day_Sum = (classRosterArray[index]->access_Day_Counts_Array()[0] + classRosterArray[index]->access_Day_Counts_Array()[1] + classRosterArray[index]->access_Day_Counts_Array()[2]);
			int total_Course_Day_Average = course_Day_Sum / 3;
			student_ID_Located = true;

			std::cout << "The student with ID (" << student_ID_Input << ") has an average day count per course of " << total_Course_Day_Average << ".\n";
		}
	}
	if (!student_ID_Located)
	{
		std::cout << "The student with student ID (" << student_ID_Input << ") was NOT able to be located.\n";
	}
}


// (E.3.E) - Method to print invalid email addresses found in the roster.

void Roster::printInvalidEmails()
{

	bool invalid_Email_Located = false;

	for (int index = 0; index < total_Students_On_Roster; index++)
	{
		if (classRosterArray[index] != NULL)
		{
			std::string student_Email_Address = classRosterArray[index]->access_Email_Address();

			if (student_Email_Address.find('@') == std::string::npos ||
				student_Email_Address.find('.') == std::string::npos ||
				student_Email_Address.find(' ') != std::string::npos) {

				invalid_Email_Located = true;

				std::cout << "Located Invalid Email Address (" << student_Email_Address << ") for student ID (" << classRosterArray[index]->access_Student_ID() << ").\n";
			}
		}
	}
	if (!invalid_Email_Located)
	{
		std::cout << "No invalid emails were located!\n";
	}
}


// (E.3.F) - Method to print students in the roster by degree program.

void Roster::printByDegreeProgram(DegreeProgram degree_Program) {

	for (int index = 0; index < total_Students_On_Roster; index++)
	{
		if (classRosterArray[index] != NULL)
		{
			if (classRosterArray[index]->access_Degree_Program() == degree_Program)
			{
				classRosterArray[index]->print();
			}
		}
	}
}
