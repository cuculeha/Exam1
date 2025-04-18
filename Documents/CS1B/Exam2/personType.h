#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>
#include "courseType.h"

using namespace std;

class personType
{	
	public:
	// Setters
	void setFName (string fN);	
	void setLName (string lN);
	void setAddress ( string addr );
	void setHeight (double ht );
	void setDOB (string bdate);
	void setGender ( char gen);

	// Getters
	string getFName () const;
	string getLName () const;
	string getAddress () const;
	double getHeight () const;
	string getDOB () const;
	char getGender () const;
	
	// Constructors
	personType();
	personType (string firstName, string lastName );
	personType (string firstName, string lastName, string addr, char gen, string bdate, double ht );
	
	// copy constructor
	personType (const personType &another);
	//Destructor
	virtual~personType();

	// Print function
	virtual void print() const = 0;

	// Operator Overloading Functions
	bool operator<(const personType& b) const;

	// Counters declaration
	static void incPeopleCount () 	{	peopleCount++; };
	static int getPeopleCount () 		{	return peopleCount;	}

	private:
	string fName;
	string lName;
	string address;
	double height;
	string DOB;
	char gender;
	static int peopleCount;
};

#endif
