#ifndef PROFESSORTYPE_H
#define PROFESSORTYPE_H

#include "personType.h"
class professorType :public personType
{

	friend istream &operator>> (istream &in, professorType& obj);
public:
	void setEmpID (string EmpID);
	void setDep (string dpt);
	void setDegree (string dg);
	void incCourseCount() {	courseCount++; }
	// Getters
	string getEmpID () const;
	string getDep () const;
	string getDegree () const;
	int getCount() const;
	void teachCourse (courseType *newCourse);
	static int getProfCount () 		{	return profCount;	}
	static void incProfCount() {	++profCount; }

	// Constructors
	professorType();
	~professorType();
	// Print methods
	void print() const override;

	private:
	string employeeID;
	string department;
	string degree;
	int courseCount;
	static int profCount;
	courseType *courses[3];
}; 

#endif
