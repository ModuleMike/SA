#pragma once
#include "degree.h"


// (D.1) - Defines student class

class Student {

private:

	// (D.1) - Private variables for Student class

	std::string student_ID;
	std::string first_Name;
	std::string last_Name;
	std::string email_Address;
	int student_Age;
	int first_Course_Day_Count;
	int second_Course_Day_Count;
	int third_Course_Day_Count;
	int day_Counts_Array[3];
	DegreeProgram degree_Program;


public:

	// (D.1) - The default Student constructor.

	Student();


	// (D.2.D) - The parameterized student constructor.

	Student(
		std::string student_ID,
		std::string first_Name,
		std::string last_Name,
		std::string email_Addresss,
		int student_Age,
		int first_Course_Day_Count,
		int second_Course_Day_Count,
		int third_Course_Day_Count,
		DegreeProgram degree_Program
	);


	// Student Destructor

	~Student();


	// (D.2.A) - Accessor methods to access student data.

	std::string access_Student_ID();

	std::string access_First_Name();

	std::string access_Last_Name();

	std::string access_Email_Address();

	int access_Student_Age();

	int* access_Day_Counts_Array();

	DegreeProgram access_Degree_Program();


	// (D.2.B) - Mutator methods to set or update student's data.

	void mutate_Student_ID(std::string student_ID);

	void mutate_First_Name(std::string first_Name);

	void mutate_Last_Name(std::string last_Name);

	void mutate_Email_Address(std::string email_Address);

	void mutate_Student_Age(int student_Age);

	void mutate_Day_Counts_Array(int first_Course_Day_Count, int second_Course_Day_Count, int third_Course_Day_Count);

	void mutate_Degree_Program(DegreeProgram degree_Program);


	// (D.2.E) - Method to print student's data.

	void print();
}; 
