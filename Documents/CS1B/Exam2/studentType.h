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
	static void incStudentCount () 	{	studentCount++; 	}
	void addCourse (courseType *newCourse );

	double getGPA() const;
	string getID() const;
	string getClassification() const;
	static int getStudentCount () 		{	return studentCount++;	}
	int getCount () { return courseCount; }

	studentType();
	studentType(string fName, string lName);
	studentType(string fName, string lName, double studentGPA, string studentID, string studentCLS);
	~studentType();
	void print() const override;

private:
  string id; //added every id 'should' be unique
	double gpa;
	string classification;
	courseType *courses[3];
	int courseCount;
	static int studentCount;
};

#endif
