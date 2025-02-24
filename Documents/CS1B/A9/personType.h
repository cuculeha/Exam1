#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>
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

	// Print function 
	void print () const;

	// Equal function
	bool equalData ( const personType &person2 ) const;

	private:
	string fName;
	string lName;
	string address;
	double height;
	string DOB;
	char gender;
};

#endif
