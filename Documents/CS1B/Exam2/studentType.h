#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H

#include <iostream>
#include "courseType.h"
#include "personType.h"

using namespace std;

class studentType:public personType
{

	friend ostream &operator<< (ostream &out, const studentType& obj);
	friend istream &operator>> (istream &in, studentType& obj);

public:
	void setGPA (double studentGPA);  
	void setID (string studentID);
	void setClassification (string studentCLS);
	static void incStudentCount () 	{	++studentCount; 	}
	void addCourse (courseType** courses, int totalCourses );
	void incCourseCount() { courseCount++; };

	double getGPA() const;
	string getID() const;
	string getClassification() const;
	static int getStudentCount () 		{	return studentCount;	}
	int getCount () { return courseCount; }

	studentType();
	~studentType();
	void print() const override;
	void printByRow () const;

private:
  string id; //added every id 'should' be unique
	double gpa;
	string classification;
	string tempCourseIDs [5];
	courseType *courses[5];
	int courseCount;
	static int studentCount;
};

#endif
