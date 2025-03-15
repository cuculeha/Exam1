#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>
using namespace std;

class personType
{
	public:
	// Setters
	void setFullName (string full);	
	void setAddress ( string addr );
	void setHeight (double ht );
	void setDOB (string bdate);
	void setGender ( char gen);

	// Getters
	string getFullName () const;
	string getAddress () const;
	double getHeight () const;
	string getDOB () const;
	char getGender () const;

	// Constructors
	personType();
	personType (string full );
	personType (string full, string addr, char gen, string bdate, double ht);

	//Destructor
	~personType();

	// Print function 
	void print () const;

	private:
	string fullName;
	string address;
	double height;
	string DOB;
	char gender;
};

#endif
