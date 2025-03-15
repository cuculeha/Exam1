#include <iostream>
#include <iomanip>
#include <string>
#include "personType.h"
using namespace std;

// Setters definition
void personType :: setFullName (string full)	{		fullName = full;	}
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
string personType :: getFullName () const	{	return fullName;	}
string personType :: getAddress () const	{	return address;	}
double personType :: getHeight () const	{	return height;	}
string personType :: getDOB () const	{	return DOB;	}
char personType :: getGender () const	{	return gender;	}

// Constructors
personType::personType ()
{
	address = "UNSET";
	gender = 'X';
	DOB = "UNSET";
	height = 10;
	fullName = "UNSET";
}
personType::personType (string full)
{
	fullName = full;
}

personType::personType (string full, string addr, char gen, string bdate, double ht )
{
	fullName = full;
	address = addr;
	gender = gen;
	DOB = bdate;
	height = ht;
}

// Destructor
personType:: ~personType ()
{
	//cout << fName << " " << lName << " object destroyed...\n";
}


// print function
void personType :: print () const
{
	cout << "Name    : " << getFullName() << endl;
	cout << "Address : " << getAddress() << endl;
	cout << "Gender  : " << getGender() << endl;
	cout << "DOB     : " << getDOB () << endl;
	cout << "Height  : " << getHeight() << " inches\n";
}
