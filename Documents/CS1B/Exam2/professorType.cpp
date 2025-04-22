#include<iostream>
#include <iomanip>
#include <limits>
#include "personType.h"
#include "professorType.h"
#include "selectionSort.h"
using namespace std;
int professorType::profCount = 0;
const int MAX_PROF_PER_COURSE = 3;

// Setters
void professorType:: setEmpID (string EmpID) {	employeeID = EmpID;	}
void professorType:: setDep (string dpt)	{	department = dpt;	}
void professorType:: setDegree (string dg){	degree = dg;	}

// Getters
string professorType :: getEmpID () const	{	return employeeID;	}
string professorType :: getDep () const	{	return department;	}
string professorType :: getDegree () const	{	return degree;	}
int professorType :: getCount () const { return courseCount; }

void professorType :: print () const
{	
	setColour(96);
	string full;
	cout << "┌───────────────────────────────────────────────────────────────────────────────────────┐\n";
	cout << "│ Type : Professor                                                                      │\n";
	char firstLetter = getFName()[0];
	full = getLName() + ", " + firstLetter + ".";
	cout << "│ Name : " << left << setw(15) << full << " ";
	cout << "Gender : " << left << setw(11) << getGender() << " ";
	cout << "Height : " << left << setw(32) << getHeight() << " │\n";
	cout << "│ DOB : " << left << setw(16) << getDOB() << " ";
	cout << "Address : " << left << setw(52) << getAddress() << " │\n";
	cout << "│ Professor ID : " << left << setw(8) << getEmpID();
	cout << "Department : " << left << setw(8) << getDep();
	cout << "Degree : " << left << setw(32) << getDegree() << " │\n";
	cout << "│ ───────────────────────────────────────────────────────────────────────────────────── │\n";
	cout << "│ Assigned Courses (sorted):                                                            │\n";
	
	bool hasCourse = false;

		for (int i = 0; i < courseCount; ++i) {
    	if (courses[i] != nullptr) {
        hasCourse = true;
			string fullInfo = courses[i]->getSection() + " - " + courses[i]->getTitle();
        cout << "│   " << left << setw(83) << fullInfo << " │\n";
    			}
			}

				if (!hasCourse) {
    			cout << "(No assigned courses)" << endl;
		}
	cout << "└───────────────────────────────────────────────────────────────────────────────────────┘\n";
	resetColour();
}

professorType::professorType()
{
	for (int i =0; i < 3; i++){
		courses[i] = nullptr;
	}
	courseCount = 0;
	employeeID = "";
	department = "";
	degree = "";
}

professorType:: ~professorType()
{

}

void professorType :: briefPrint () const
{
	string fullName = getLName() + ", " + getFName();
	cout << " " <<left << setw(20) << fullName;
	cout << "│ " << left << setw (9) << getEmpID();
	cout << "│ " << left << setw(14) << getDep();
	cout << "│ " << left << setw(12) << getCount ();
	cout << endl;
}

void professorType::teachCourse(courseType** courseList, int totalCourses)
{
    courseCount = 0; // reset

    for (int i = 0; i < 3; ++i) { // Professors max 3 courses
        if (tempCourseIDs[i] != "") {
            for (int j = 0; j < totalCourses; ++j) {
                if (courseList[j] != nullptr && courseList[j]->getCourseID() == tempCourseIDs[i]) {
                    safeAssign(courseList[j]);
                    break; // matched and assigned
                }
            }
        }
    }
}

void professorType::printByRow() const
{
    string fullName = getLName() + ", " + getFName();
    
    // First line - student info
    cout << " " << left << setw(20) << fullName
         << "│ " << left << setw(10) << getEmpID()
         << "│ " << left << setw(6) << getDep()
         << "│ " << fixed << setprecision(2) << setw(5) << getCount()
         << "│ ";
		if (courseCount > 0)
		cout << courseCount << " courses assigned\n";

    	if (courseCount == 0) {
        cout << "(No assigned courses)" << endl;
    	}
		cout << " Assigned Courses :\n";
		cout << "      Section │ Title                       │ Day   │ Time         │ Room      \n";

		if (courseCount > 0)
		cout << "     ─────────┴─────────────────────────────┴───────┴──────────────┴──────────── \n";
		// Courses Assigned to the professor
		for (int i = 0 ; i < courseCount ; i++)
		{
			if (courses[i] != nullptr ){
			// Print course details
			cout << "      " << left << setw(8) << courses[i]->getSection() << "│ " << left << setw (28) << trimString(courses[i]->getTitle(), 25) << "│ ";
			cout << left << setw (6) << courses[i]->getDays() << "│ " << left << setw (15) << courses[i]->getTime() << "│ ";
			cout << left << setw (13) << courses[i]->getRoom() << endl;
			// Print each persons
			courses[i]->showStudents();
			cout << endl;
			}

		}
}

istream &operator>> (istream &in, professorType &obj)
{
	string profID;
	string first;
	string last;
	string gender;
	string height;
	string address;
	string dob;
	string dep;
	string degree;

	getline (in, profID, '|');
	obj.setEmpID (profID);

	getline (in, first, '|');
	obj.setFName (first);

	getline (in, last, '|');
	obj.setLName (last);

	getline (in, gender, '|');
	obj.setGender (gender[0]);

	getline(in, height, '|');
		if (!height.empty()) {
    obj.setHeight(stoi(height));
		} else {
    obj.setHeight(0); // or some safe default
		}

	getline (in, address, '|');
	obj.setAddress (address);

	getline (in, dob, '|');
	obj.setDOB (dob);

	getline (in, dep, '|');
	obj.setDep (dep);

	getline (in, degree, '|');
	obj.setDegree (degree);

	string coursesTemp;
	getline(in, coursesTemp);      // read the *whole courses line* here

	stringstream courseStream(coursesTemp);   // now OK to wrap it
	string courseID;
	obj.courseCount = 0;

	// Split
		while (getline(courseStream, courseID, ',')) {
    	if (obj.courseCount < 3) {
        obj.tempCourseIDs[obj.courseCount] = courseID;
        obj.courseCount++;
			}
		}
	return in;
}


void professorType :: manualInput () 

{
	string id;
	string first;
	string last;
	string gender;
	string height;
	string address;
	string dob;
	string dg;
	string dpt;

	cout << "Professor ID : \n";
	getline (cin, id);
	setEmpID (id);

	cout << "First Name : \n";
	getline (cin, first);
	setFName (first);

	cout << "Last Name : \n";
	getline (cin, last);
	setLName (last);

	cout << "Gender : \n";
	getline (cin, gender);
	setGender (gender[0]);

	cout << "Height : \n";
	getline (cin, height);
	setHeight (stoi(height));

	cout << "Address : \n";
	getline (cin, address);
	setAddress (address);

	cout << "DOB : \n";
	getline (cin, dob);
	setDOB (dob);

	cout << "Degree : \n";
	getline (cin, dg);
	setDegree (dg);

	cout << "Department : \n";
	getline (cin, dpt);
	setDep (dpt);

}

void professorType::safeAssign(courseType* c)
{
    if (courseCount >= 3) {
        cout << "Professor already assigned to 3 courses. Cannot assign more.\n";
        return;
    }

    if (c->getNumProf() >= MAX_PROF_PER_COURSE) {
        cout << "Warning: Course " << c->getCourseID() << " already has maximum instructors assigned.\n";
        return;
    }

    courses[courseCount] = c;
    courseCount++;
    c->setNumProf(c->getNumProf() + 1); // Don't forget to increment number of professors!

    setColour(93);
    cout << "┌──────────────────────────────────────────────────────────────────┐\n";
    cout << "   Professor successfully assigned to course " << c->getCourseID() << endl;
    cout << "└──────────────────────────────────────────────────────────────────┘\n";
    resetColour();

    SelectionSort(courses, courseCount, [](courseType* a, courseType* b) {
        return *a < *b;
    });
}
