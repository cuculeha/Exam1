#include <iostream>
#include "courseType.h"
using namespace std;

int courseType:: census = 0;

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
	capacity = 20;
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
	cout << "Course Type Print method here\n";
}

istream &operator>> (istream &in, courseType &obj)
{
	string id;
	string title = "";
	string time = "";
	string days = "";
	
	cout << "┌──────────────────────────────────────────────────────────────────┐\n";
	cout << "│               Adding a new course in Saddleback College          │\n";
	cout << "└──────────────────────────────────────────────────────────────────┘\n";
	cout << "\nCourse Section ID : ";
	getline (in, id);
	in.ignore(10, '\n');
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

	return in;

}
