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
void readFile (const string &input, studentType** &students, professorType** &professors, courseType** &courses);
void addNewStudent(studentType**& students, studentType* newStudent);
void addNewProf (professorType** &professors, professorType* newProfessor);
void addNewCourse (courseType** &courses, courseType* newCourse);
void studentwithCourses ( studentType** students);
void profwithCourses ( professorType** professors);
void courseDisplay (courseType** courses);
void displayAll (personType** people, int totalPersons);

int main ()
{

	personType** people = nullptr;
	studentType** students = nullptr;
	professorType** professors = nullptr;
	courseType** courses = nullptr;

	char choice;
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
				cout << "File's data is already in system\n";
				cout << "Press Enter to Continue\n";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			break;

			case '2':
			cout << "Not implemented yet...\n";
			cout << "Press Enter to Continue\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			break;

			case '3':
			studentwithCourses (students);
			break;

			case '4':
			profwithCourses (professors);
			break;

			case '5':
			courseDisplay (courses);
			break;

			case '6':
			cout << "Selected Option 6\n";
			break;

			case '7':
			cout << "Selected Option 7\n";
			break;

			case '8':
			int totalPersons = studentType::getStudentCount() + professorType::getProfCount();
			people = new personType*[totalPersons];
				int index = 0;

				// Fill in the pointers with studentType and professorType
						for (int i = 0; i < studentType::getStudentCount(); i++) {
    						people[index++] = students[i];
								}
						for (int i = 0; i < professorType::getProfCount(); i++) {
    						people[index++] = professors[i];
							}
			displayAll (people, totalPersons);
			break;

		}
		// Sort the data everytime the program repeats
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

	for (int i = 0; i < professorType::getProfCount(); i++)
		{
			delete professors[i];
		}

	for (int i = 0; i < courseType::getCourseCount(); i++)
		{
			delete courses[i];
		}
	delete [] students;
	delete [] professors;
	delete [] courses;
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

void readFile(const string &input, studentType** &students, professorType** &professors, courseType** &courses)
{
    ifstream infile(input);
    if (!infile) {
        cout << "Failed to open the file..Press Enter to Continue\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    string keyword;
    bool readingCourses = false;
    bool readingProfessors = false;
	 bool readingStudents = false;


 	while (getline(infile, keyword)) {
    if (keyword == "COURSES_START") {
        readingCourses = true;
        continue;
    } else if (keyword == "COURSES_END") {
        readingCourses = false;
        continue;
    }
    else if (keyword == "PROFESSORS_START") {
        readingProfessors = true;
        continue;
    }
    else if (keyword == "PROFESSORS_END") {
        readingProfessors = false;
        continue;
    }
    else if (keyword == "STUDENTS_START") {
        readingStudents = true;
        continue;
    }
    else if (keyword == "STUDENTS_END") {
        readingStudents = false;
        continue;
    }

    if (readingCourses) {
        stringstream ss(keyword);
        courseType* tempCourse = new courseType();
        ss >> *tempCourse;
        addNewCourse(courses, tempCourse);
    }
    else if (readingProfessors) {
        stringstream ss(keyword);
        professorType* tempProf = new professorType();
        ss >> *tempProf;
        addNewProf(professors, tempProf);
    }
    else if (readingStudents) {
        stringstream ss(keyword);
        studentType* tempStudent = new studentType();
        ss >> *tempStudent;
        addNewStudent(students, tempStudent);
    }
}

    cout << "Finished reading data successfully!\nPress Enter to Continue\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < studentType::getStudentCount(); ++i) {
    	students[i]->addCourse(courses, courseType::getCourseCount() );
			}

		for (int i = 0; i < professorType::getProfCount(); ++i) {
    	professors[i]->teachCourse(courses, courseType::getCourseCount());
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

void studentwithCourses (studentType** students)
{
	SelectionSort (students, studentType:: getStudentCount(), [](studentType *a, studentType *b) 
			{
				return *a < *b;
	});
	system("clear");
	setColour(96);

	cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
	cout << "│                                 Student Enrollment Report (SORTED)                               │\n";
	cout << "├────────────────────┬───────────┬───────┬──────┬──────────────────────────────────────────────────┤\n";
	cout << left << setw(22) << "│Name" << left << setw (15) << " │ ID" << left << setw(10) << "│Class";
	cout << left << setw(9) << "│ GPA" << left << setw (52) << "│ Courses (sorted) " << " │\n";
	cout << "└────────────────────┴───────────┴───────┴──────┴──────────────────────────────────────────────────┘\n";
	cout << endl;
	resetColour();

	for (int i =0 ; i < studentType::getStudentCount (); i ++)	{
		students[i]->printByRow();
		cout << " ────────────────────────────────────────────────────────────────────────────────────────────────── \n";
		}
	setColour(96);
	cout << right << setw (45) << "TOTAL STUDENT LISTED : " << studentType::getStudentCount();
	resetColour();
	cout << "\n────────────────────────────────────────────────────────────────────────────────────────────────────\n";
	cout << "Press Enter to Continue..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void profwithCourses (professorType** professors)
{
	SelectionSort (professors, professorType:: getProfCount(), [](professorType *a, professorType *b) 
			{
				return *a < *b;
	});
	system("clear");
	setColour(96);

	cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
	cout << "│                              Professor Course Load Report (SORTED)                               │\n";
	cout << "├────────────────────┬───────────┬───────┬──────┬──────────────────────────────────────────────────┤\n";
	cout << left << setw(22) << "│Name" << left << setw (15) << " │ ID" << left << setw(10) << "│Dept";
	cout << left << setw(9) << "│ Load" << left << setw (52) << "│ Assigned Courses (sorted) " << " │\n";
	cout << "└────────────────────┴───────────┴───────┴──────┴──────────────────────────────────────────────────┘\n";
	cout << endl;
	resetColour();

	for (int i =0 ; i < professorType::getProfCount (); i ++)	{
		professors[i]->printByRow();
		cout << " ────────────────────────────────────────────────────────────────────────────────────────────────── \n";
		}
	setColour(96);
	cout << right << setw (55) << "TOTAL PROFESSOR LISTED : " << professorType::getProfCount();
	resetColour();
	cout << "\n────────────────────────────────────────────────────────────────────────────────────────────────────\n";
	cout << "Press Enter to Continue..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}


void courseDisplay (courseType** courses)
{
	SelectionSort (courses, courseType:: getCourseCount(), [](courseType *a, courseType *b) 
			{
				return *a < *b;
	});
 	system("clear");
	setColour(96);
	cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
	cout << "│                                  Course Enrollment Report (SORTED)                               │\n";
	cout << "├────────┬─────────────────────────────┬───────┬──────────────┬─────────┬────────┬────────┬────────┤\n";
	cout << left << setw(8) << "│ Section" << left << setw (32) << "│ Title" << left << setw(10) << "│ Days";
	cout << left << setw(17) << "│ Time" << left << setw (12) << "│ Room " << left << setw(11) << "│ Cap";
	cout << left << setw(10) << "│ Inst" << left << setw (12) << " │ Enr " << "│\n";
	cout << "└────────┴─────────────────────────────┴───────┴──────────────┴─────────┴────────┴────────┴────────┘\n";
	resetColour();

	for (int i =0 ; i < courseType::getCourseCount (); i ++)	{
		courses[i]->printByRow();
		cout << " ────────────────────────────────────────────────────────────────────────────────────────────────── \n";
		}

	setColour(96);
	cout << right << setw (55) << "TOTAL COURSES LISTED : " << courseType::getCourseCount();
	resetColour();
	cout << "\n────────────────────────────────────────────────────────────────────────────────────────────────────\n";
	cout << "Press Enter to Continue..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void displayAll (personType** people, int totalPersons)
{
		for (int i = 0; i < totalPersons; i++) {
    		people[i]->print();
		}

	cout << "Press Enter to Continue..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
