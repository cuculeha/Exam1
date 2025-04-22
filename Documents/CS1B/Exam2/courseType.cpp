#include <iostream>
#include <iomanip>
#include "courseType.h"
#include "studentType.h"
#include "selectionSort.h"
using namespace std;

int courseType:: census = 0;
int courseType:: courseCount = 0;

// Setters
void courseType :: setSection (string secID)	{ section = secID ;	}
void courseType :: setCourseID (string CourseID )	{ id = CourseID ;	}
void courseType :: setTitle (string name)	{  title = name;	}
void courseType :: setDays (string day)	{  days = day;	}
void courseType :: setTime (string timeofCourse )	{ time = timeofCourse;	}
void courseType :: setRoom ( string place )	{  room = place;	}
void courseType :: setCapacity (int cap )	{  capacity = cap;	}
void courseType :: setEnrollmentCount (int enrollCount )	{  enrolledCount = enrollCount;	}
void courseType :: incEnroll () {	enrolledCount++; }
void courseType :: setNumProf ( int numProf  )	{ numInstructors  = numProf;	}

// Getters
string courseType:: getSection() const	{  return section ;	}
string courseType:: getCourseID() const	{  return id ;	}
string courseType :: getTitle() const	{	return title;}
string courseType :: getDays() const	{  return days;	}
string courseType :: getTime() const	{  return time;	}
string courseType :: getRoom() const	{  return room;	}
int courseType :: getCapacity() const	{  return capacity;	}
int courseType :: getEnrolledCount() const	{  return enrolledCount;	}
int courseType :: getNumProf() const	{  return numInstructors;	}

courseType::courseType ()
{
	section = ""; title = ""; days = ""; time = ""; room = ""; capacity = 0; enrolledCount = 0; numInstructors = 0; 
	enrolledStudents = nullptr; ++census;
}

courseType::~courseType() {
    if (enrolledStudents != nullptr) {
        delete[] enrolledStudents;
    }
}
void courseType::printByRow() const
{
	cout << " " << left << setw(8) << getSection() << "│ " << left << setw (28) << trimString(getTitle(), 25) << "│ ";
	cout << left << setw (6) << getDays() << "│ " << left << setw (15) << getTime() << "│ ";
	cout << left << setw (13) << getRoom() << "│ " << left << setw(7) << getCapacity() << "│ ";
	cout << left << setw(7) << getNumProf () << "│ " << left << setw(7) << getEnrolledCount() << endl;

}

istream &operator>> (istream &in, courseType &obj)
{
	string code;
	string id;
	string title = "";
	string time = "";
	string days = "";
	string room = "";
	string quantity;

	getline(in, code, '|');
	obj.setCourseID (code);

	getline(in, id, '|');
	obj.setSection(id);

	getline(in, title, '|');
	obj.setTitle(title);

	getline(in, days, '|');
	obj.setDays(days);

	getline(in, time, '|');
	obj.setTime(time);

	getline(in, room, '|');
	obj.setRoom(room);

	getline(in, quantity, '|');
	obj.setCapacity(stoi(quantity));

	obj.allocateEnrolledArray();

return in;
}

bool courseType:: operator< (const courseType& b) const
{
	return (getSection() < b.getSection());
}

void courseType::allocateEnrolledArray() {
    if (enrolledStudents == nullptr && capacity > 0) {
        enrolledStudents = new studentType*[capacity];
        for (int i = 0; i < capacity; ++i) {
            enrolledStudents[i] = nullptr;
        }
    }
}

void courseType::enrollStudent(studentType* newStudent) {
    if (enrolledCount == capacity) {
        cout << "Course is full! Cannot enroll more students.\n";
        return;
    }

    if (enrolledStudents == nullptr) {
        enrolledStudents = new studentType*[capacity];
        for (int i = 0; i < capacity; ++i) {
            enrolledStudents[i] = nullptr;
        }
    }

    // INSERT THE NEW STUDENT
    enrolledStudents[enrolledCount++] = newStudent;
}


void courseType::showStudents() const
{
    if (enrolledStudents == nullptr) {
        cout << "No students enrolled in this course yet.\n";
        return;
    }

	   cout << setw (15) << left << "" << "Enrolled students :\n";
		cout << setw (18) << left << "" << " Name          │ ID      │ Class   │ GPA \n";
		cout << setw (18) << left << "" << "───────────────┴─────────┴─────────┴──────\n";
    for (int i = 0; i < enrolledCount; i++)
    {
        if (enrolledStudents[i] != nullptr) {
			string format = enrolledStudents[i]->getLName() + ", " + enrolledStudents[i]->getFName()[0] + ".";
            cout << setw (18) << left << "" << setw (15) << left << format << "│ ";
				cout << setw (8) << left << enrolledStudents[i]->getID() << "│ " ;
				cout << setw (8) << left << enrolledStudents[i]->getClassification() << "│ " ;
				cout << setw (8) << left << enrolledStudents[i]->getGPA();
				cout << endl;
        }
    }
}
