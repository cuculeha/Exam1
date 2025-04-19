#include<iostream>
#include <iomanip>
#include <limits>
#include "personType.h"
#include "professorType.h"
using namespace std;
int professorType::profCount = 0;

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
	cout << left << setw(10) << getFName() << " " << left << setw(10) << getLName () << endl;
}

professorType::professorType()
{
	for (int i =0; i < 3; i++){
		courses[i] = nullptr;
	}
	courseCount = 0;
	employeeID = "";
	department = "";
	degree = "";
}

professorType:: ~professorType()
{

}

void professorType :: teachCourse (courseType *newCourse )
{
	if (courseCount < 3){
		courses[courseCount] = newCourse;
		}

	else 	{
	cout << "Cannot assign professor: maximum teaching load of 3 courses reached. Press Enter to continue\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}	
}


istream &operator>> (istream &in, professorType &obj)
{
	string full;
	string fName = "";
	string lName = "";
	string address;
	double height;
	string dob;
	string id;
	string dpt;
	string dg;

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

	cout << "\nEmployee ID : ";
	getline (in, id );
	obj.setEmpID(id);

	cout << "\nDepartment : ";
	getline (in, dpt );
	obj.setDep(dpt);

	cout << "\nDegree : ";
	getline (in, dg);
	obj.setDegree(dg);

	return in;
}
