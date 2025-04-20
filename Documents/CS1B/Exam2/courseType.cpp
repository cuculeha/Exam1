#include <iostream>
#include <iomanip>
#include "courseType.h"
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
void courseType :: setEnrollmentCount (int enrollCount )	{  enrollCount = enrolledCount;	}
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
	cout << left << setw(20) << getSection () << " " << getTitle () << endl;
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
	cout << code << endl;

	getline(in, id, '|');
	obj.setSection(id);
	cout << id << endl;

	getline(in, title, '|');
	obj.setTitle(title);
	cout << title << endl;

	getline(in, days, '|');
	obj.setDays(days);
	cout << days << endl;

	getline(in, time, '|');
	obj.setTime(time);
	cout << time << endl;

	getline(in, room, '|');
	obj.setRoom(room);
	cout << room << endl;

	getline(in, quantity, '|');
	obj.setCapacity(stoi(quantity));
	cout << quantity << endl;

	return in;
}

bool courseType:: operator< (const courseType& b) const
{
	return (getSection() == b.getSection());
}
