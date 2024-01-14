#include "degree.h"
#include "student.h"
#include "roster.h"
#include <iostream>

/**
*
*
* The Main function serves as the entry point for the program.
* It demonstrates the program's functionality and outputs the results to the console for validation.
*
**/

int main() {


	// Defines the total number of students.

	const int total_Students = 5;


	// (A) - Initializes the array containing the data for each student.

	const std::string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Michael,Smith,mSmith@anon.edu,36,13,53,71,SOFTWARE"
	};



	// (F.2) - Create an instance of the Roster class.

	Roster classRoster;


	// (F.3) - Itterates through the student data to parse and add each student to the roster instance.

	std::cout << "------------------------------------------------------------------\n";
	std::cout << "** System Status ** \n";
	std::cout << "Importing student information into roster... \n\n";
	std::cout << "------------------------------------------------------------------\n\n";
	for (int index = 0; index < total_Students; index++) {

		classRoster.parse_Student_Data(studentData[index]);

	}


	// (F.4) - Prints the data for all students in the roster.

	std::cout << "** System Status ** \n";
	std::cout << "Displaying student roster...\n\n";
	std::cout << "Student Roster: \n\n";

	classRoster.printAll();

	std::cout << "------------------------------------------------------------------\n";


	// (F.4) - Prints all invalid email addresses found in the roster.

	std::cout << "\n** System Status **";
	std::cout << "\nChecking for invalid email addresses...\n\n";
	std::cout << "Invalid Email Address Report: \n\n";

	classRoster.printInvalidEmails();

	std::cout << "\n------------------------------------------------------------------\n";


	// (F.4) - Itterates through the roster and calculates and prints the average number of days each student has spent in their courses.

	std::cout << "\n** System Status **\n";
	std::cout << "Calculating average for total course days... \n\n";

	std::cout << "Average Days in Course Report: \n\n";

	for (int index = 0; index < total_Students; index++) {

		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[index]->access_Student_ID());

	}

	std::cout << "\n------------------------------------------------------------------\n";


	// (F.4) -  Prints the data for students enrolled in the 'SOFTWARE' degree program.

	std::cout << "\n** System Request **\n";
	std::cout << "Searching for students enrolled in the (Software) degree program... \n\n";

	std::cout << "Software Degree Program Results: \n\n";

	classRoster.printByDegreeProgram(SOFTWARE);

	std::cout << "\n------------------------------------------------------------------\n";


	// (F.4) - Attempts to remove a student with ID 'A3' from the roster.

	std::cout << "\n** System Request **\n";
	std::cout << "Removing student with student ID (A3)...\n";

	classRoster.remove("A3");

	std::cout << "\n\n------------------------------------------------------------------\n";


	// (F.4) - Prints the updated roster to verify the removal of the student with student ID 'A3'.

	std::cout << "\n** System Status ** \n";
	std::cout << "Displaying updated student roster...\n\n";
	std::cout << "\nUpdated Student Roster : \n\n";

	classRoster.printAll();

	std::cout << "------------------------------------------------------------------\n";


	// (F.4) - Attempts to remove the student with ID 'A3' again to demonstrate error handling and validation of deletion.

	std::cout << "\n** System Request **\n";
	std::cout << "Removing student with student ID (A3)...\n";

	classRoster.remove("A3");

	std::cout << "------------------------------------------------------------------\n\n";


	// (F.5) - Releases the dynamically allocated memory created in Roster.

	std::cout << "** System Request **\n";
	std::cout << "Release dynamically allocated memory created in roster...\n\n";

	system("pause");

	return 0;

}