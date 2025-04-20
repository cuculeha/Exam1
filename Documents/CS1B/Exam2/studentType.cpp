#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "personType.h"
#include "studentType.h"
#include "courseType.h"
#include "selectionSort.h"
using namespace std;
int studentType::studentCount = 0;

// Setters
void studentType :: setGPA (double studentGPA) {  gpa = studentGPA;	}
void studentType ::setID (string studentID)	{  id = studentID;	}
void studentType :: setClassification (string studentCLS)	{  classification = studentCLS;	}

//Getters
double studentType:: getGPA() const{  return gpa;	}
string studentType :: getID() const	{	return id;	}
string studentType :: getClassification() const	{  return classification;	}
studentType:: ~studentType()	{	}


studentType:: studentType()
{
	for (int i = 0; i < 5 ; i++)	{
	courses[i]= nullptr;	}
	courseCount = 0;
	gpa = 2.5;
	id = "";
	classification = "";
}

void studentType :: print () const
{	
	setColour(93);
	string full;
	cout << "┌─────────────────────────────────────────────────────────────────────────────┐\n";
	cout << "│ Type : Student                                                              │\n";
	char firstLetter = getFName()[0];
	full = getLName() + ", " + firstLetter + ".";
	cout << "│ Name : " << left << setw(15) << full << " ";
	cout << "Gender : " << left << setw(15) << getGender() << " ";
	cout << "Height : " << left << setw(18) << getHeight() << " │\n";
	cout << "│ DOB : " << left << setw(16) << getDOB() << " ";
	cout << "Address : " << left << setw(42) << getAddress() << " │\n";
	cout << "│ Student ID : " << left << setw(10) << getID();
	cout << "Classification : " << left << setw(8) << getClassification();
	cout << "GPA : " << left << setw(21) << getGPA() << " │\n";
	cout << "│ ─────────────────────────────────────────────────────────────────────────── │\n";
	cout << "│ Assigned Courses (sorted):                                                  │\n";
	
	bool hasCourse = false;

		for (int i = 0; i < courseCount; ++i) {
    	if (courses[i] != nullptr) {
        hasCourse = true;
			string fullInfo = courses[i]->getSection() + " - " + courses[i]->getTitle();
        cout << "│   " << left << setw(73) << fullInfo << " │\n";
    			}
			}

				if (!hasCourse) {
    			cout << "(No assigned courses)" << endl;
		}
	cout << "└─────────────────────────────────────────────────────────────────────────────┘\n";
	resetColour();
}


void studentType::printByRow() const
{
    string fullName = getLName() + ", " + getFName();
    string shortClass = getClassification().substr(0, 2);

    // First line - student info
    cout << " " << left << setw(20) << fullName
         << "│ " << left << setw(10) << getID()
         << "│ " << left << setw(6) << shortClass
         << "│ " << fixed << setprecision(2) << setw(5) << getGPA()
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
        cout << "(No enrolled courses)" << endl;
    }
}
// Add course in a student
void studentType::addCourse(courseType** courseList, int totalCourses)
{
    courseCount = 0; // reset

    for (int i = 0; i < 5; ++i) { // max tempCourseIDs
        for (int j = 0; j < totalCourses; ++j) { // search real courses
            if (courseList[j] != nullptr && courseList[j]->getCourseID() == tempCourseIDs[i]) {
    				if (courseList[j]->getEnrolledCount() < courseList[j]->getCapacity()) { 
        						// Capacity available for student to take more classes
        						if (courseCount < 5) { 
            				courses[courseCount] = courseList[j];
            				courseCount++;
            				courseList[j]->incEnroll(); // Increase course enrollment
        } 
        else {
            cout << "Warning: Student already enrolled in maximum 5 courses. Extra courses ignored." << endl;
        }
    } 
    else {
        cout << "Warning: Course " << courseList[j]->getCourseID() << " is full. Cannot enroll.\n";
    }
    break; // once found, don't search more
		}

   }
    }
	SelectionSort(courses, courseCount, [](courseType* a, courseType* b) {
    return *a < *b; // compare objects pointed by a and b
		});
}


ostream &operator<< (ostream &out, const studentType &obj)
{
	out << "Operator for extracting\n";
	return out;
}

istream &operator>> (istream &in, studentType &obj)
{
	string studentID;
	string first;
	string last;
	string gender;
	string height;
	string address;
	string dob;
	string gpa;
	string clss;

	getline (in, studentID, '|');
	obj.setID (studentID);
	cout << studentID << endl;

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

	getline(in, gpa, '|');
		if (!gpa.empty()) {
    obj.setGPA(stod(gpa));
			} else {
    obj.setGPA(0.0);
			}
	cout << gpa << endl;

	getline (in, clss, '|');
	obj.setClassification (clss);
	cout << clss << endl;

	string coursesTemp;
	getline(in, coursesTemp);      // read the *whole courses line* here

	stringstream courseStream(coursesTemp);   // now OK to wrap it
	string courseID;
	obj.courseCount = 0;

	// Split
		while (getline(courseStream, courseID, ',')) {
    	if (obj.courseCount < 5) {
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
