#ifndef COURSETYPE_H
#define COURSETYPE_H

#include <iostream>
#include <string>
using namespace std;

class courseType
{

	friend istream &operator>> (istream &in, courseType& obj);
	public:
	// Setters
	void setSecID (string secID);
	void setTitle (string name);	
	void setDays (string day);
	void setTime ( string timeofCourse );
	void setRoom ( string place );
	void setCapacity ( int cap );
	void setEnrollmentCount ( int enrollCount );
	void setNumProf ( int numProf );
	static void incCourseCount() { courseCount++; }
	static void incCensus () { census++ ; }

	// Getters
	string getSecID () const;
	string getTitle () const;
	string getDays () const;
	string getTime () const;
	string getRoom () const;
	int getCapacity () const;
	int getEnrolledCount () const;
	int getNumProf () const;
	static int getCourseCount() { return courseCount; }
	static int getCensus () { return census; }

	// Constructors
	courseType();

	//Destructor
	~courseType();

	// Print function 
	void print () const;
	
	// Operator Overloading
	bool operator<(const courseType& b) const;
	private:
	string section;
	string title;
	string days;
	string time;
	string room;
	int capacity;
	int enrolledCount;
	int numInstructors;
	static int courseCount;
	static int census;
	
};
#endif
