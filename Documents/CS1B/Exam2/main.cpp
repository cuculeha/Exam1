#include <iostream>
#include <cstdlib>
#include <string>
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
void readFile (const string &input, studentType** &students, professorType** &professors, courseType** &courses);
void addNewStudent(studentType**& students, studentType* newStudent);
void addNewProf (professorType** &professors, professorType* newProfessor);
void addNewCourse (courseType** &courses, courseType* newCourse);
void enrollStudent (studentType** students, courseType** courses);

int main ()
{

	//personType** people = nullptr;
	studentType** students = nullptr;
	professorType** professors = nullptr;
	courseType** courses = nullptr;

	studentType *tempStudent = nullptr;
	professorType *tempProf = nullptr;
	courseType *tempCourse = nullptr;

	char choice;
	char toAddManually;
	bool readFileAlready = false;

	do {
	choice = showMainMenu();
		switch (choice)
		{
			case '0':
			return 0;
			break;

			case '1':
			if (readFileAlready == false){
			readFile("input.txt", students, professors, courses);
			readFileAlready = true;
			}

			else{
				cout << "Option 1 wont do anything since data from the file is already in system\n";
				cout << "Press Enter to Continue\n";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			break;

			case '2':
			toAddManually = addDataManually ();
			system ("clear");
				switch (toAddManually){
					case '1':
					tempStudent = new studentType ();
					cin >> *tempStudent;
					addNewStudent (students, tempStudent);
					cout << "Successfully Added a New Student in Saddleback College. Press Enter\n";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;

					case '2':
					tempProf = new professorType ();
					cin >> *tempProf;
					addNewProf (professors, tempProf);
					cout << "Successfully Added a New Professor in Saddleback College. Press Enter\n";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;

					case '3':
					tempCourse = new courseType ();
					cin >> *tempCourse;
					addNewCourse (courses, tempCourse);
					cout << "Successfully Added a New Course in Saddleback College. Press Enter\n";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;

					case '4':
					enrollStudent (students, courses);
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

		}
		// Sort the data everytime the program repeats
		SelectionSort (students ,studentType::getStudentCount());
		SelectionSort (professors, professorType::getProfCount());
		SelectionSort (courses, courseType:: getCourseCount(), [](courseType *a, courseType *b) 
			{
				return *a < *b;
				});
	}
	while (choice != '0');

	for (int i = 0; i < studentType::getStudentCount(); i++)
		{
			delete students[i];
		}


	return 0;
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
	cout << "│     (4) -   Enroll an existing student in a course               │\n";
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

void readFile (const string &input, studentType** &students, professorType** &professors, courseType** &courses)
{
	ifstream infile(input);
	studentType *tempStudent = nullptr;
	professorType *tempProf = nullptr;
	courseType *tempCourse = nullptr;

	if (!infile){
		cout << "Failed to open the file..Press Enter to Continue\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	
	string keyword;
	while (getline(infile,keyword))
	{
		if (keyword == "ProfessorType"){
				cout << "Professor Type\n";
				tempProf = new professorType();
				infile >> *tempProf;
				addNewProf (professors, tempProf);
		}

		else if (keyword == "StudentType"){
				tempStudent = new studentType();
				infile >> *tempStudent;
				addNewStudent (students, tempStudent);

		}

		else if (keyword == "CourseType"){
			tempCourse = new courseType ();
			infile >> *tempCourse;
		}

		else if (keyword == "End")
			{	
				cout << endl;
				system("clear");
				cout << "END OF FILE.. SUCCESSFULY READ DATA\n";
				cout << "Press Enter to Continue\n";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		else
		cout << "Unknown Type\n";
	}
}

void addNewStudent(studentType**& students, studentType* newStudent)
{
	studentType** newArray = new studentType*[studentType::getStudentCount() + 1];
		if (students != nullptr){
		for (int i = 0; i < studentType::getStudentCount(); ++i) {
        newArray[i] = students[i];
    }
	}
		newArray[studentType::getStudentCount()] = newStudent;
		delete[] students;
		students = newArray;
		studentType::incStudentCount();
}

void addNewProf (professorType**& professors, professorType* newProfessor)
{
		professorType** newArray = new professorType*[professorType::getProfCount() + 1];
		if (professors != nullptr){
		for (int i = 0; i < professorType::getProfCount(); ++i) {
        newArray[i] = professors[i];
    }
	}
		newArray[professorType::getProfCount()] = newProfessor;
		delete[] professors;
		professors = newArray;
		professorType::incProfCount();
}


void addNewCourse(courseType**& courses, courseType* newCourse)
{
	courseType** newArray = new courseType*[courseType::getCourseCount() + 1];
		if (courses != nullptr){
		for (int i = 0; i < courseType::getCourseCount(); ++i) {
        newArray[i] = courses[i];
    }
	}
		newArray[courseType::getCourseCount()] = newCourse;
		delete[] courses;
		courses = newArray;
		courseType::incCourseCount();
}

void enrollStudent (studentType** students, courseType** courses)
{	
	int studentIndex;
	int courseIndex;

	if (studentType::getStudentCount() == 0)
		{
			cout << "No Students available in system\n.. Add students first\n";
			cout << "Press Enter to Continue\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return;
	}

	if (courseType::getCourseCount() == 0)
		{
			cout << "No Courses available in system.. Add Courses first\n";
			cout << "Press Enter to Continue\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return;
	}

	// At this line, there are students and courses in the system..
	// LookUp for students..

	cout << "Search for students in Saddleback College\n";
	studentIndex = searchObjectList(students, studentType::getStudentCount());

	if (studentIndex != -1) // Means valid student is picked
	{
		cout << "Search for courses in Saddleback College\n";
		courseIndex = searchObjectList(courses, courseType::getCourseCount());

	}

	// Enroll student in a course..
	students[studentIndex]->addCourse(courses[courseIndex]);
}
