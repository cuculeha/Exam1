#include<iostream>
#include <iomanip>
#include <limits>
#include "personType.h"
#include "professorType.h"
#include "selectionSort.h"
using namespace std;
int professorType::profCount = 0;
const int MAX_PROF_PER_COURSE = 2;

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
	cout << "┌────────────────────────────────────────────────────────────────────────┐\n";
	cout << "│ Type : Professor                                                       │\n";
	char firstLetter = getFName()[0];
	full = getLName() + ", " + firstLetter + ".";
	cout << "│ Name : " << left << setw(15) << full << " ";
	cout << "Gender : " << left << setw(5) << getGender() << " ";
	cout << "Height : " << left << setw(23) << getHeight() << " │\n";
	cout << "│ DOB : " << left << setw(16) << getDOB() << " ";
	cout << "Address : " << left << setw(37) << getAddress() << " │\n";
	cout << "│ Professor ID : " << left << setw(8) << getEmpID();
	cout << "Department : " << left << setw(8) << getDep();
	cout << "Degree : " << left << setw(17) << getDegree() << " │\n";
	cout << "│ ────────────────────────────────────────────────────────────────────── │\n";
	cout << "│ Assigned Courses (sorted):                                             │\n";
	
	bool hasCourse = false;

		for (int i = 0; i < courseCount; ++i) {
    	if (courses[i] != nullptr) {
        hasCourse = true;
			string fullInfo = courses[i]->getSection() + " - " + courses[i]->getTitle();
        cout << "│   " << left << setw(68) << fullInfo << " │\n";
    			}
			}

				if (!hasCourse) {
    			cout << "(No assigned courses)" << endl;
		}
	cout << "└────────────────────────────────────────────────────────────────────────┘\n";
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

void professorType::teachCourse(courseType** courseList, int totalCourses)
{
    courseCount = 0; // reset

    for (int i = 0; i < 3; ++i) { // Professors max 3 courses
        for (int j = 0; j < totalCourses; ++j) {
            if (courseList[j] != nullptr && courseList[j]->getCourseID() == tempCourseIDs[i]) {
    				if (courseCount < 3) {
        					if (courseList[j]->getNumProf() < MAX_PROF_PER_COURSE) {
            this->courses[courseCount] = courseList[j];
            courseCount++;
            courseList[j]->setNumProf(courseList[j]->getNumProf() + 1); // Increment professor count
        } else {
            cout << "Warning: Course " << courseList[j]->getCourseID() 
                 << " already has maximum instructors assigned.\n";
        }
   		 } else {
        cout << "Cannot assign professor: maximum load of 3 courses reached." << endl;
    			}
    break; // done finding this course
				}
        }
    }

	SelectionSort(courses, courseCount, [](courseType* a, courseType* b) {
    return *a < *b;
		});

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

    bool hasCourse = false;
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i] != nullptr) {
            if (!hasCourse) {
                cout << courses[i]->getSection() << " -> " << courses[i]->getTitle() << endl;
                hasCourse = true;
            }
            else {
                cout << setw(21) << " " << "│ " 
                     << setw(10) << " " << "│ "
                     << setw(6) << " " << "│ "
                     << setw(5) << " " << "│ "
                     << courses[i]->getSection() << " -> " << courses[i]->getTitle() << endl;
            }
        }
    }

    if (!hasCourse) {
        cout << "(No assigned courses)" << endl;
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
	cout << profID << endl;

	getline (in, first, '|');
	obj.setFName (first);
	cout << first << endl;

	getline (in, last, '|');
	obj.setLName (last);
	cout << last << endl;

	getline (in, gender, '|');
	obj.setGender (gender[0]);
	cout << gender[0] << endl;

	getline(in, height, '|');
		if (!height.empty()) {
    obj.setHeight(stoi(height));
		} else {
    obj.setHeight(0); // or some safe default
		}
	cout << height << endl;

	getline (in, address, '|');
	obj.setAddress (address);
	cout << address << endl;

	getline (in, dob, '|');
	obj.setDOB (dob);
	cout << dob << endl;

	getline (in, dep, '|');
	obj.setDep (dep);
	cout << dep << endl;

	getline (in, degree, '|');
	obj.setDegree (degree);
	cout << degree << endl;

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

	// Print
	for (int i = 0; i < obj.courseCount; i++) {
    cout << obj.tempCourseIDs[i] << endl;
		}
	return in;
}
