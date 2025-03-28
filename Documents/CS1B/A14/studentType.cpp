#include <iostream>
#include "personType.h"
#include "studentType.h"

using namespace std;

void studentType :: setGPA (double studentGPA)
{
  gpa = studentGPA;
}

void studentType ::setID (string studentID)
{
  id = studentID;
}

void studentType :: setClassification (string studentCLS)
{
  classification = studentCLS;
}

double studentType:: getGPA() const
{
  return gpa;
}

string studentType :: getID() const
{
  return id;
}

string studentType :: getClassification() const
{
  return classification;
}


studentType:: studentType()
{
  gpa = 2.5;
  id = "";
  classification = "";
}

studentType::studentType(string fName, string lName)
            : personType (fName, lName)
{
  // its empty.. 
}
studentType:: studentType(string fName, string lName, double studentGPA, string studentID, string studentCLS)
            : personType (fName, lName)
{
  if (studentGPA > 2.5 )
    gpa = studentGPA;

  id = studentID;
  classification = studentCLS;
}

void studentType :: print () const
{
  personType :: print ();
  cout << "Student GPA    : " << getGPA() << endl;
  cout << "Student ID     : " << getID() << endl;
  cout << "Classification : " << getClassification() << endl;
}

bool studentType :: equalData (const studentType &another) const
{
  if (gpa == another.gpa && id == another.id && classification == another.classification &&
        personType :: equalData(another))
    return true;

  else
    return false;
}
