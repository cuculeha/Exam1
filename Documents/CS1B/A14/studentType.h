#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H

#include <iostream>
#include "personType.h"
using namespace std;

class studentType:public personType
{
public:
  void setGPA (double studentGPA);  
  void setID (string studentID);
  void setClassification (string studentCLS);

  double getGPA() const;
  string getID() const;
  string getClassification() const;

  studentType();
  studentType(string fName, string lName);
  studentType(string fName, string lName, double studentGPA, string studentID, string studentCLS);
	~studentType();
  void print()  const;
  bool equalData (const studentType &another) const;

private:
  string id; //added every id 'should' be unique
  double gpa;
  string classification; 
};

#endif
