#include <iostream>
#include <iomanip>
#include "courseType.h"
using namespace std;

int courseType:: census = 0;
int courseType:: courseCount = 0;

// Setters
void courseType :: setSecID (string secID)	{ section = secID ;	}
void courseType :: setTitle (string name)	{  title = name;	}
void courseType :: setDays (string day)	{  days = day;	}
void courseType :: setTime (string timeofCourse )	{ time = timeofCourse;	}
void courseType :: setRoom ( string place )	{  room = place;	}
void courseType :: setCapacity (int cap )	{  capacity = cap;	}
void courseType :: setEnrollmentCount (int enrollCount )	{  enrollCount = enrolledCount;	}
void courseType :: setNumProf ( int numProf  )	{ numInstructors  = numProf;	}

// Getters
string courseType:: getSecID() const	{  return section ;	}
string courseType :: getTitle() const	{	return title;}
string courseType :: getDays() const	{  return days;	}
string courseType :: getTime() const	{  return time;	}
string courseType :: getRoom() const	{  return room;	}
int courseType :: getCapacity() const	{  return capacity;	}
int courseType :: getEnrolledCount() const	{  return enrolledCount;	}
int courseType :: getNumProf() const	{  return numInstructors;	}

courseType::courseType ()
{
	section = "";
	title = "";
	days = "";
	time = "";
	room = "";
	capacity = 0;
	enrolledCount = 0;
	numInstructors = 0;
	++census;
}

courseType:: ~courseType ()
{
	cout << "courseType object destroyed...\n";
}

void courseType :: print () const
{
	cout << left << setw(20) << getSecID () << " " << getTitle () << endl;
}

istream &operator>> (istream &in, courseType &obj)
{
	string id;
	string title = "";
	string time = "";
	string days = "";
	string room = "";
	int quantity;

	cout << "┌──────────────────────────────────────────────────────────────────┐\n";
	cout << "│               Adding a new course in Saddleback College          │\n";
	cout << "└──────────────────────────────────────────────────────────────────┘\n";
	cout << "\nCourse Section ID : ";
	getline (in, id);
	obj.setSecID(id);

	cout << "\nCourse Title : ";
	getline (in, title);
	obj.setTitle(title);

	cout << "\nCourse Days : ";
	getline (in, days);
	obj.setDays(days);

	cout << "\nCourse Time : ";
	getline (in, time);
	obj.setTime(time);

	cout << "\nClassroom : ";
	getline (in, room);
	obj.setRoom(room);
	
	cout << "\nMaximum Capacity: ";
	in >> quantity;
	obj.setCapacity(quantity);
	in.ignore();

	return in;
}

bool courseType:: operator< (const courseType& b) const
{
	return (getSecID() == b.getSecID());
}
