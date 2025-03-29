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
	void setMother (personType* mom);
	void setFather (personType* dad);

	// Getters
	string getFName () const;
	string getLName () const;
	string getAddress () const;
	double getHeight () const;
	string getDOB () const;
	char getGender () const;
	personType* getMother () const;
	personType* getFather () const;

	// Constructors
	personType();
	personType (string firstName, string lastName );
	personType (string firstName, string lastName, string addr, char gen, string bdate, double ht, 
														personType *mom = nullptr, personType *dad = nullptr);
	
	// copy constructor
	personType (const personType &another);
	//Destructor
	virtual~personType();

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
	personType *mother;  ///< pointer to the mother object of this person object
	personType *father;  ///< pointer to the father object of this person object
};

#endif
