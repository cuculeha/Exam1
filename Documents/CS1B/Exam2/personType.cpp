#include <iostream>
#include <iomanip>
#include <string>
#include "personType.h"
using namespace std;


int personType::peopleCount = 0;

// Setters definition
void personType :: setFName (string fN) {	fName = fN; }
void personType :: setLName (string lN)	{		lName = lN;	}
void personType :: setAddress (string addr ){		address = addr;	}
void personType :: setHeight (double ht)	{
	if (ht < 10) {
	height = 10;}

	else if (ht > 100 ){
	height = 100;}

	else
	height = ht;
}
void personType :: setDOB (string bdate){		DOB = bdate;	}

void personType :: setGender (char gen)	{
	if (gen != 'M' && gen != 'm' && gen != 'F' && gen != 'f')
	{
		gender = 'X';
	}

	else
		gender = gen;
}

// Getters definition
string personType :: getFName () const	{	return fName; 	}
string personType :: getLName () const	{	return lName;	}
string personType :: getAddress () const	{	return address;	}
double personType :: getHeight () const	{	return height;	}
string personType :: getDOB () const	{	return DOB;	}
char personType :: getGender () const	{	return gender;	}

// Constructors
personType::personType ()
{
	fName = "UNSET";
	lName = "UNSET";
	address = "UNSET";
	gender = 'X';
	DOB = "UNSET";
	height = 10;
	++peopleCount;
}

personType::personType (string firstName, string lastName)
{
	fName = firstName;
	lName = lastName;
	address = "UNSET";
	gender = 'X';
	DOB = "UNSET";
	height = 10;
	++peopleCount;
}

personType::personType (string firstName, string lastName, string addr, char gen, string bdate, double ht )
{
	fName = firstName;
	lName = lastName;
	address = addr;
	gender = gen;
	DOB = bdate;
	height = ht;
	++peopleCount;
}

// copy constructor
personType::personType (const personType &another)
{	cout << "Copy constructor called and it copies data from " << another.fName << " " << another.lName << endl;
	fName = another.fName;
	lName = another.lName;
	address = another.address;
	gender = another.gender;
	DOB = another.DOB;
	height = another.height;
	++peopleCount;
}

// Destructor
personType:: ~personType ()
{

}


// Operator overloading (unchanged except for the < operator)
bool personType:: operator< (const personType& b) const
{
	if (getLName() == b.getLName()){
	return getFName() < b.getFName();
	}

 return getLName() < b.getLName();

}

ostream& operator<<(ostream& out, const personType& obj)
{
	obj.print(out);  // virtual call
    return out;
}
