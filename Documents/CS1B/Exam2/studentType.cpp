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
	cout << "┌───────────────────────────────────────────────────────────────────────────────────────┐\n";
	cout << "│ Type : Student                                                                        │\n";
	char firstLetter = getFName()[0];
	full = getLName() + ", " + firstLetter + ".";
	cout << "│ Name : " << left << setw(15) << full << " ";
	cout << "Gender : " << left << setw(15) << getGender() << " ";
	cout << "Height : " << left << setw(28) << getHeight() << " │\n";
	cout << "│ DOB : " << left << setw(16) << getDOB() << " ";
	cout << "Address : " << left << setw(52) << getAddress() << " │\n";
	cout << "│ Student ID : " << left << setw(10) << getID();
	cout << "Classification : " << left << setw(8) << getClassification();
	cout << "GPA : " << left << setw(31) << getGPA() << " │\n";
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
								courseType::incCensus();  // Increment Census
								courseList[j]->enrollStudent(this);  // Tell course to take students
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

	getline(in, gpa, '|');
		if (!gpa.empty()) {
    obj.setGPA(stod(gpa));
			} else {
    obj.setGPA(0.0);
			}

	getline (in, clss, '|');
	obj.setClassification (clss);

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

	return in;
}

void studentType :: manualInput () 

{
	string id;
	string first;
	string last;
	string gender;
	string height;
	string address;
	string dob;
	string gpa;
	string classf;

	cout << "Student ID : \n";
	getline (cin, id);
	setID (id);

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

	cout << "GPA : \n";
	getline (cin, gpa);
	setGPA (stod(gpa));

	cout << "Classification : \n";
	getline (cin, classf);
	setClassification (classf);

}
