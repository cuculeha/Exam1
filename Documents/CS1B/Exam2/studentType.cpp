#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "personType.h"
#include "studentType.h"
#include "courseType.h"
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

void studentType :: print() const
{
	cout << left << setw(10) << getFName () << " " << setw(10) << getLName() << endl;
}

void studentType::printByRow() const
{
    string fullName = getLName() + ", " + getFName();
    string shortClass = getClassification().substr(0, 2);

    // First line - student info
    cout << "│" << left << setw(20) << fullName
         << "| " << left << setw(10) << getID()
         << "| " << left << setw(6) << shortClass
         << "| " << fixed << setprecision(2) << setw(5) << getGPA()
         << "| ";

    bool hasCourse = false;
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i] != nullptr) {
            if (!hasCourse) {
                cout << courses[i]->getSecID() << " - " << courses[i]->getTitle() << endl;
                hasCourse = true;
            }
            else {
                cout << setw(20) << " " << "| " 
                     << setw(10) << " " << "| "
                     << setw(6) << " " << "| "
                     << setw(5) << " " << "| "
                     << courses[i]->getSecID() << " - " << courses[i]->getTitle() << endl;
            }
        }
    }

    if (!hasCourse) {
        cout << "(No enrolled courses)" << endl;
    }
}
// Add course in a student
void studentType :: addCourse (courseType *newCourse)
{
	if (courseCount < 5) {
			courses[courseCount] = newCourse;
			courseCount++;
	}
	else{ cout << "Cannot enroll student: maximum course load of 5 reached. Press Enter to Continue\n"; 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

}

ostream &operator<< (ostream &out, const studentType &obj)
{
	out << "Operator for extracting\n";
	return out;
}

istream &operator>> (istream &in, studentType &obj)
{
	string full;
	string fName = "";
	string lName = "";
	string address;
	double height;
	string dob;
	double gpa;
	string classification;
	string id;

	cout << "\nFull Name : ";
	getline (in, full);
	// Separate the full name to first and last
	int position;
	position = full.find(" ");
	fName.append (full, 0, position);
	lName.append(full, position+1);
	obj.setFName(fName);
	obj.setLName(lName);

	cout << "\nAddress : ";
	getline (in, address);
	obj.setAddress(address);

	cout << "\nHeight : ";
	in >> height;
	obj.setHeight(height);
	in.ignore();

	cout << "\nDOB : ";
	getline (in, dob );
	obj.setDOB(dob);

	cout << "\nGPA : ";
	in >> gpa;
	obj.setGPA(gpa);
	in.ignore();

	cout << "\nID : ";
	getline (in, id );
	obj.setID(id);

	cout << "\nClassification : ";
	getline (in, classification);
	obj.setClassification(classification);

	return in;
}

