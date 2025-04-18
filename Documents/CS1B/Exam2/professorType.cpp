#include<iostream>
#include <iomanip>
#include <limits>
#include "personType.h"
#include "professorType.h"
using namespace std;

// Setters
void professorType:: setEmpID (string EmpID) {	employeeID = EmpID;	}
void professorType:: setDep (string dpt)	{	department = dpt;	}
void professorType:: setDegree (string dg){	degree = dg;	}

// Getters
string professorType :: getEmpID () const	{	return employeeID;	}
string professorType :: getDep () const	{	return department;	}
string professorType :: getDegree () const	{	return degree;	}
int professorType :: getCount () const { return courseCount; }

void professorType :: print () const
{
	cout << "Call for personType details\n";
	cout << left << setw (15) << "Employee ID" << left << setw (20) << "Department" << "Degree\n";
	cout << left << setw (15) << getEmpID() ;
	cout << left << setw (20) << getDep();
	cout << getDegree () << endl;
	cout << endl;
}

professorType::professorType()
{
	for (int i =0; i < 5; i++){
		courses[i] = nullptr;
	}
	courseCount = 0;
	employeeID = "";
	department = "";
	degree = "";
}

professorType:: professorType (string fn, string ln)
					: personType (fn, ln)
{
	for (int i =0; i < 5; i++){
		courses[i] = nullptr;
	}
	courseCount = 0;
	employeeID = "";
	department = "";
	degree = "";
}

professorType :: professorType (string fn, string ln, string addr, double ht, string bdate,
										char gender, string id, string dpt, string dg)
					: personType (fn, ln, addr, gender, bdate, ht)
{
	for (int i =0; i < 5; i++){
		courses[i] = nullptr;
	}
	courseCount = 0;
	employeeID = id;
	department = dpt;
	degree = dg;
}

professorType:: ~professorType()
{

}

void professorType :: teachCourse (courseType *newCourse )
{
	if (courseCount < 5){
		courses[courseCount] = newCourse;
		courseCount ++;
		}

	else 	{
	cout << "A professor can only add up to 5 courses to teach. Press Enter to continue\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}	
}
