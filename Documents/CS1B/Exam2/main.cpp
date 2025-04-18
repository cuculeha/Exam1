#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <cstdlib>
#include <fstream>
#include <limits>
#include "personType.h"
#include "professorType.h"
#include "studentType.h"
#include "selectionSort.h"
#include <limits>
using namespace std;

char showMainMenu ();
char addDataManually ();
void readFile (const string &input);
void createNewStudent ();
void createNewProfessor ();
void createNewCourse ();

int main ()
{

	personType** people = nullptr;
	char choice;
	char toAddManually;
	do {
	choice = showMainMenu();
		switch (choice)
		{
			case '0':
			return 0;
			break;

			case '1':
			cout << "Selected Option 1\n";
			break;

			case '2':
			toAddManually = addDataManually ();

				switch (toAddManually){
					case '1':
					cout << "Creating a student type...\n";
					break;

					case '2':
					cout << "Creating professorType..\n";
					break;
				};
			break;

			case '3':
			cout << "Selected Option 3\n";
			break;

			case '4':
			cout << "Selected Option 4\n";
			break;

			case '5':
			cout << "Selected Option 5\n";
			break;

			case '6':
			cout << "Selected Option 6\n";
			break;

			case '7':
			cout << "Selected Option 7\n";
			break;

			case '8':
			cout << "Selected Option 8\n";
			break;

			case '9':
			cout << "Selected Option 9\n";
			break;
		}
	}
	while (choice != '0');
	return 0;
	system ("clear");
}


char showMainMenu ()
{
	char choice;

	system ("clear");
	setColour(96);
	cout << "┌──────────────────────────────────────────────────────────────────┐\n";
	cout << "│                       Course EnrollMent System                   │\n";
 	cout << "│                                                                  │\n";
	cout << "│     (1) -   Optional - Load Data From A File                     │\n";
	cout << "│     (2) -   Add people and course manually                       │\n";
	cout << "│     (3) -   Print all students and their enrolled courses        │\n";
	cout << "│     (4) -   Print all professors and their assigned courses      │\n";
	cout << "│     (5) -   Generate Course Enrollment Report                    │\n";
	cout << "│     (6) -   Print Course Catalog Review                          │\n";
	cout << "│     (7) -   Generate Professor Course Load Report                │\n";
	cout << "│     (8) -   Display all people and their associated courses      │\n";
	cout << "├──────────────────────────────────────────────────────────────────┤\n";
	cout << "│     (0) -   QUIT                                                 │\n";
	cout << "└──────────────────────────────────────────────────────────────────┘\n";
	resetColour();
	cout << "Enter your choice 1 - 8 ( 0 to exit )\n";
	cin.get (choice);
	cin.ignore (100, '\n');

		while (choice < '0' || choice > '8' )
		{
			cout << choice << " is not a valid option. Please enter a number between 1 and 8 (0 to exit).\n";
			cin.get (choice);
			cin.ignore (100, '\n');
		}
	return choice; 
}


char addDataManually ()
{
	char choice;

	system ("clear");
	setColour(32);
	cout << "┌──────────────────────────────────────────────────────────────────┐\n";
	cout << "│                         Manual Data Entry Menu                   │\n";
 	cout << "│                                                                  │\n";
	cout << "│     (1) -   Add A New Student                                    │\n";
	cout << "│     (2) -   Add a New Professor                                  │\n";
	cout << "│     (3) -   Add a New Course                                     │\n";
	cout << "│     (4) -   Enroll and existing student in a course              │\n";
	cout << "│     (5) -   Assign an exising professor to a course              │\n";
	cout << "├──────────────────────────────────────────────────────────────────┤\n";
	cout << "│     (0) -   Quit and Back To Main Menu                           │\n";
	cout << "└──────────────────────────────────────────────────────────────────┘\n";
	resetColour();
	cout << "Enter your choice 1 - 5 ( 0 back to main menu )\n";
	cin.get (choice);
	cin.ignore (100, '\n');

		while (choice < '0' || choice > '5' )
		{
			cout << choice << " is not a valid option. Please enter a number between 1 and 5 (0 back to main menu).\n";
			cin.get (choice);
			cin.ignore (100, '\n');
		}
	return choice;
}

void readFile (const string &input)
{
	ifstream infile(input);
	
	if (!infile){
		cout << "Failed to open the file..Press Enter to Continue\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	
	string keyword;
	while (getline(infile,keyword))
	{
		if (keyword == "Professor Type"){
				cout << "Professor Type\n";
		}

		else if (keyword == "Student Type"){
				personType *p = new studentType();
				infile >> *(dynamic_cast<studentType*>(p));
				cout << "Student Type..\n";
		}
		else if (keyword == "CourseType"){
			cout << "created courseType";
		}
		else
		cout << "Unknown Type\n";
	}
}
