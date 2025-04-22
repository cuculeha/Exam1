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

int activeAllocations = 0;

void* operator new(std::size_t size) {
    ++activeAllocations;
    return malloc(size);
}

void operator delete(void* ptr) noexcept {
    --activeAllocations;
    free(ptr);
}

using namespace std;

char showMainMenu ();
void readFile (const string &input, studentType** &students, professorType** &professors, courseType** &courses);
void addNewStudent(studentType** &students, studentType* newStudent);
void addNewProf (professorType** &professors, professorType* newProfessor);
void addNewCourse (courseType** &courses, courseType* newCourse);
void studentwithCourses ( studentType** students);
void profwithCourses ( professorType** professors);
void courseDisplay (courseType** courses);
void displayAll (personType** people, int totalPersons);
void professorLoad (professorType** professors);
void beforeQuit();
char handleManually ();
void addData (char manualInput, professorType** &professors, studentType** &students, courseType** &courses );
void assignCourseManually (char manual, professorType** &professors, studentType** &students, courseType** &courses);

int main ()
{

	personType** people = nullptr;
	studentType** students = nullptr;
	professorType** professors = nullptr;
	courseType** courses = nullptr;

	char choice;
	char manualInput;
	bool dataLoaded = false;
	bool fileLoaded = false;

	do {
	choice = showMainMenu();
		switch (choice)
		{
			
			case '1':
			if (!fileLoaded){
			readFile("input.txt", students, professors, courses);
			fileLoaded = true;
			}

			else{
				cout << "File's data is already in system\n";
				cout << "Press Enter to Continue\n";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			break;

			case '2':
			manualInput = handleManually ();
			if (manualInput > '0' && manualInput < '4'){
			addData (manualInput, professors, students, courses );
			dataLoaded = true;
			}

			else if (manualInput > '3' && manualInput < '6')	{
				assignCourseManually (manualInput, professors, students, courses);
				}
			break;

			case '3':
			if (!dataLoaded && !fileLoaded){	
			cout << "Nothing to show for student with courses. Load the data first (Option 1 & 2)\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else{
			studentwithCourses (students);
			}
			break;

			case '4':
			if (!dataLoaded && !fileLoaded) {	
			cout << "Nothing to show for professors with courses. Load the data first (Option 1 & 2)\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
			profwithCourses (professors);
			}
			break;

			case '5':
			if (!dataLoaded && !fileLoaded){	
			cout << "Nothing to show for courses report. Load the data first (Option 1 & 2)\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else{
			courseDisplay (courses);
			}
			break;

			case '6':
			if (!dataLoaded && !fileLoaded){	
			cout << "Nothing to show for professorLoad. Load the data first (Option 1 & 2)\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else{
			professorLoad (professors);
			}
			break;

			case '7':
			if (dataLoaded || fileLoaded)	{
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
			}

			else{
			cout << "Nothing to show. Load the file first (Option 1 & 2)\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			break;

			case '8':
			{
		
			if (students != nullptr){
			for (int i = 0; i < studentType::getStudentCount(); i++){
								delete students[i];	}
								delete [] students;
				}
			if (professors != nullptr ){
			for (int i = 0; i < professorType::getProfCount(); i++){
								delete professors[i];	}
								delete [] professors;
				}
			if (courses != nullptr ){
					for (int i = 0; i < courseType::getCourseCount(); i++){
								delete courses[i];	}
								delete [] courses;
				}
			if (people != nullptr) delete [] people;
				beforeQuit();
				}
				return 0;

			}
		// Sort the data everytime the program repeats
	}
	while (choice != '8');

		return 0;
}


char handleManually()
{

	bool canEnroll = false;
	bool canAssign = false;
	if (studentType::getStudentCount() > 0 && courseType::getCourseCount() > 0 ) { canEnroll = true;	}
	if (professorType::getProfCount() > 0 && courseType::getCourseCount() > 0 ) { canAssign = true;	}

	char choice;
	system ("clear");
	setColour(96);
	cout << "┌──────────────────────────────────────────────────────────────────┐\n";
	cout << "│                       Manual Data Entry Menu                     │\n";
 	cout << "│                                                                  │\n";
	cout << "│     (1) -   Add A New Student                                    │\n";
	cout << "│     (2) -   Add A New Professor                                  │\n";
	cout << "│     (3) -   Add A New Course                                     │\n";
	if (canEnroll){
	cout << "│     (4) -   Enroll an existing student in a Course               │\n";
	}
	if (canAssign){
	cout << "│     (5) -   Assign an existing professor in a course             │\n";
	}
	cout << "├──────────────────────────────────────────────────────────────────┤\n";
	cout << "│     (0) -   QUIT                                                 │\n";
	cout << "└──────────────────────────────────────────────────────────────────┘\n";
	resetColour();

	if (canEnroll == true && canAssign == true){
	cout << "Enter your choice 1 - 5\n";
	cin.get (choice);
	cin.ignore (100, '\n');

		while (choice < '0' || choice > '5' )
		{
			cout << choice << " is not a valid option. Please enter a number between 1 and 5. (0 to quit)\n";
			cin.get (choice);
			cin.ignore (100, '\n');
		}

		return choice;
	}

	else if (canEnroll){
	cout << "Enter your choice 1 - 4. Currently cant assign professor to course..\n";
	cin.get (choice);
	cin.ignore (100, '\n');

		while (choice < '0' || choice > '4' )
		{
			cout << choice << " is not a valid option. Please enter a number between 1 and 4. (0 to quit)\n";
			cin.get (choice);
			cin.ignore (100, '\n');
		}

		return choice;
	}

	else if (canAssign){
	cout << "Enter your choice (1 - 3) or 5. Currently cant enroll student in a course..\n";
	cin.get (choice);
	cin.ignore (100, '\n');

		while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '5')
		{
			cout << choice << " is not a valid option. Please enter a number between (1 - 3) or 5 (0 to quit)\n";
			cin.get (choice);
			cin.ignore (100, '\n');
		}

		return choice;
	}


	else
	{
	cout << "Enter your choice (1 - 3). Currently cant enroll student in a course and assign professor to a course..\n";
	cin.get (choice);
	cin.ignore (100, '\n');

		while (choice < '0' || choice > '3')
		{
			cout << choice << " is not a valid option. Please enter a number between (1 - 3) \n";
			cin.get (choice);
			cin.ignore (100, '\n');
		}

	}
	return choice;
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
	cout << "│     (6) -   Generate Professor Course Load Report                │\n";
	cout << "│     (7) -   Display all people and their associated courses      │\n";
	cout << "├──────────────────────────────────────────────────────────────────┤\n";
	cout << "│     (8) -   QUIT                                                 │\n";
	cout << "└──────────────────────────────────────────────────────────────────┘\n";
	resetColour();
	cout << "Enter your choice 1 - 8\n";
	cin.get (choice);
	cin.ignore (100, '\n');

		while (choice < '1' || choice > '8' )
		{
			cout << choice << " is not a valid option. Please enter a number between 1 and 8.\n";
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
		cout << "┌──────────────────────────────────────────────────────────────────┐\n";
		cout << "│ Successfully Read the File. Press Enter To Continue...           │\n";
		cout << "└──────────────────────────────────────────────────────────────────┘\n";
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
		delete[] students;
	}
		newArray[studentType::getStudentCount()] = newStudent;
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
	int coursesCensus = courseType::getCensus();
	double avgLoad = static_cast<double>(coursesCensus)/studentType::getStudentCount ();
	cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
	cout << "│                                 Student Enrollment Report (SORTED)                               │\n";
	cout << "├────────────────────┬───────────┬───────┬──────┬──────────────────────────────────────────────────┤\n";
	cout << "│ Name               │ ID        │ Class │ GPA  │ Courses Enrolled (Sorted)                        │\n";
	cout << "└────────────────────┴───────────┴───────┴──────┴──────────────────────────────────────────────────┘\n";
	cout << endl;
	resetColour();
	for (int i =0 ; i < studentType::getStudentCount (); i ++)	{
		if (students[i]!= nullptr){
		students[i]->printByRow();
		cout << " ────────────────────────────────────────────────────────────────────────────────────────────────── \n";
		}
	}
	setColour(96);
	cout << "                  TOTAL STUDENT LISTED : " << studentType::getStudentCount();
	cout << "\n                          CENSUS VALUE : " << coursesCensus;
	cout << "\n            AVERAGE SUDENT COURSE LOAD : " << avgLoad ;
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
	setColour(92);

	cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
	cout << "│                              Professor Course Load Report (SORTED)                               │\n";
	cout << "├────────────────────┬───────────┬───────┬──────┬──────────────────────────────────────────────────┤\n";
	cout << left << setw(22) << "│Name" << left << setw (15) << " │ ID" << left << setw(10) << "│Dept";
	cout << left << setw(9) << "│ Load" << left << setw (52) << "│ Assigned Courses (sorted) " << " │\n";
	cout << "└────────────────────┴───────────┴───────┴──────┴──────────────────────────────────────────────────┘\n";
	cout << endl;
	resetColour();

	int colourCode;
	for (int i =0 ; i < professorType::getProfCount (); i ++)	{
		colourCode = (i % 2 == 0) ? 93 : 96;
		setColour(colourCode);
		professors[i]->printByRow();
		cout << "════════════════════════════════════════════════════════════════════════════════════════════════════ \n";
		}
	setColour(92);
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
	cout << "┌───────────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
	cout << "│                                  Course Enrollment Report (SORTED)                                    │\n";
	cout << "├────────┬─────────────────────────────┬───────┬──────────────┬──────────────┬────────┬────────┬────────┤\n";
	cout << "│ Section│ Title                       │ Days  │ Time         │ Room         │ Cap    │ Ins    │  Enr   │\n";
	cout << "└────────┴─────────────────────────────┴───────┴──────────────┴──────────────┴────────┴────────┴────────┘\n";
	resetColour();

	for (int i =0 ; i < courseType::getCourseCount (); i ++)	{
		courses[i]->printByRow();
		cout << " ──────────────────────────────────────────────────────────────────────────────────────────────────────\n";
		}

	setColour(96);
	cout << right << setw (55) << "TOTAL COURSES LISTED : " << courseType::getCourseCount();
	resetColour();
	cout << "\n─────────────────────────────────────────────────────────────────────────────────────────────────────────\n";
	cout << "Press Enter to Continue..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void displayAll (personType** people, int totalPersons)
{
		system("clear");
		cout << "┌───────────────────────────────────────────────────────────────────────────────────────┐\n";
		cout << "│                             ALL PEOPLE REPORT (SORTED)                                │\n";
		cout << "└───────────────────────────────────────────────────────────────────────────────────────┘\n";
		SelectionSort (people, totalPersons, [](personType *a, personType *b) 
			{
				return *a < *b;
		});

		for (int i = 0; i < totalPersons; i++) {
    		people[i]->print();
		}

	cout << "Press Enter to Continue..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void professorLoad (professorType** professors)
{

	SelectionSort (professors, professorType:: getProfCount(), [](professorType *a, professorType *b) 
			{
				return *a < *b;
	});

	system("clear");
	int totalCourses = 0;
	double avgLoad;

	cout << "┌──────────────────────────────────────────────────────────────┐\n";
	cout << "│               Course Enrollment Report (SORTED)              │\n";
	cout << "├────────────────────┬──────────┬───────────────┬──────────────┤\n";
	cout << "│  Name              │ ID       │ Dept       	│ # of courses │\n";
	cout << "└────────────────────┴──────────┴───────────────┴──────────────┘\n";

	for (int i =0 ; i < professorType::getProfCount (); i ++)	{
		professors[i]->briefPrint();
		cout << " ────────────────────────────────────────────────────────────── \n";
		totalCourses += professors[i]->getCount();
		}
	setColour(96);
	cout << " TOTAL PROFESSOR LISTED : " << professorType::getProfCount();
	avgLoad = static_cast<double>(totalCourses)/professorType::getProfCount ();
	cout << "\n AVERAGE LOAD : " << avgLoad << endl;
	resetColour();
	cout << "────────────────────────────────────────────────────────────────\n";
	cout << "Press Enter to Continue..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void beforeQuit()
{
	if (activeAllocations == 0)
    std::cout << "Yeayy.. All dynamic memory was successfully deallocated.\n";
	else
    std::cout << " Opss.. Memory leak detected. You missed deleting something.\n";

	cout << "Press Enter to Quit..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void addData (char manualInput, professorType** &professors, studentType** &students, courseType** &courses )
{
	switch (manualInput)	{
		case '1':	{
		studentType* tempS = new studentType();
		tempS->manualInput();
		addNewStudent(students, tempS);
		break;
		}

		case '2': {
		professorType* tempP = new professorType();
		tempP->manualInput();
		addNewProf(professors, tempP);
		break;
		}

		case '3':	{
		courseType* tempC = new courseType();
		tempC->manualInput();
		addNewCourse(courses, tempC);
		break;
		}

	}
}

void assignCourseManually (char manual, professorType** &professors, studentType** &students, courseType** &courses)
{
	string id;
	string courseID;

	switch (manual){	
	case '4': {
	cout << "Enter the student ID : ";
	getline (cin, id);
	
	studentType* s = findById(students, studentType::getStudentCount(), id, &studentType::getID);
	if (s == nullptr) {
   cout << "Student with ID : " << id << " not found. Press Enter to Continue";
 	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return;
		}
	

	cout << "Enter Course ID the student want to enroll in :";
	getline (cin, courseID);

	courseType* c = findById(courses, courseType::getCourseCount(), courseID, &courseType::getCourseID);
	if ( c == nullptr ){
		cout << "Course ID Not Found. Press Enter to Continue\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}

	// Finally both courseID and student ID is valid..
 	s->safeEnroll(c);
	cout << "Press Enter to Continue\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	break;


	case '5':
	{
	cout << "Enter the professor ID : ";
	getline (cin, id);
	
	professorType* p = findById(professors, professorType::getProfCount(), id, &professorType::getEmpID);
	if (p == nullptr) {
   cout << "Professor with ID : " << id << " not found. Press Enter to Continue";
 	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return;
		}
	

	cout << "Enter Course ID for the professor to teach :";
	getline (cin, courseID);

	courseType* c = findById(courses, courseType::getCourseCount(), courseID, &courseType::getCourseID);
	if ( c == nullptr ){
		cout << "Course ID Not Found. Press Enter to Continue\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}

	// Finally both courseID and student ID is valid..
   p->safeAssign(c);
	cout << "Press Enter to Continue\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	break;
	}

return;

}
