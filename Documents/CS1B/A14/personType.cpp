#include <iostream>
#include <iomanip>
#include "personType.h"
using namespace std;

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

void personType :: setMother (personType* mom)
{
	mother = mom;
}

void personType :: setFather (personType* dad)
{
	father = dad;
}

// Getters definition
string personType :: getFName () const	{	return fName; 	}
string personType :: getLName () const	{	return lName;	}
string personType :: getAddress () const	{	return address;	}
double personType :: getHeight () const	{	return height;	}
string personType :: getDOB () const	{	return DOB;	}
char personType :: getGender () const	{	return gender;	}
personType* personType :: getMother () const { return mother; };
personType* personType :: getFather () const { return father; };

// Constructors
personType::personType ()
{
	fName = "UNSET";
	lName = "UNSET";
	address = "UNSET";
	gender = 'X';
	DOB = "UNSET";
	height = 10;
	mother = nullptr;
	father = nullptr;
}

personType::personType (string firstName, string lastName)
{
	fName = firstName;
	lName = lastName;
}

personType::personType (string firstName, string lastName, string addr, char gen, string bdate, double ht,
								personType* mom, personType* dad )
{
	fName = firstName;
	lName = lastName;
	address = addr;
	gender = gen;
	DOB = bdate;
	height = ht;
	mother = nullptr;
	father = nullptr;
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
	mother = another.mother;
	father = another.father;
}

// Destructor
personType:: ~personType ()
{
	cout << fName << " " << lName << " object destroyed...\n";
}

// print function
void personType :: print () const
{
	cout << "Name    : " << getFName() << " " << getLName() << endl;
	cout << "Address : " << getAddress() << endl;
	cout << "Gender  : " << getGender() << endl;
	cout << "DOB     : " << getDOB () << endl;
	cout << "Height  : " << getHeight() << " inches\n";
	if (mother != nullptr)
	{
		cout << "Mother Name : " << mother->getFName () << " " << mother->getLName () << endl;
	}
	else
		cout << "Mother Name : Unknown\n";

	if (father != nullptr)
	{
		cout << "Father name : " << father->getFName () << " " << father->getLName () << endl;
	}

	else
	cout << "Father Name : Unknown\n";

}

// equals strings
bool personType :: equalData (const personType &person2) const
{
	if (fName == person2.fName && lName == person2.lName && address == person2.address &&
		height == person2.height && DOB == person2.DOB && gender == person2.gender)	{
			return true;
	}

	else	{
			return false;
		}
}
