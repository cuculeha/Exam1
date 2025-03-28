#ifndef PROFESSORTYPE_H
#define PROFESSORTYPE_H

#include "personType.h"
class professorType :public personType
{

public:
	void setEmpID (string EmpID);
	void setDep (string dpt);
	void setDegree (string dg);

	string getEmpID () const;
	string getDep () const;
	string getDegree () const;

	// Constructors
	professorType();
	professorType (string fn, string ln);
	professorType (string fn, string ln, string addr, double ht, 
						string bdate, char gender, string id, string dpt, string dg, personType *mom, personType *dad);

	// Print methods
	void print () const;
	
	// Compare professorType
	bool compareProfessor ( const professorType &anotherProf) const;
private:
	string employeeID;
	string department;
	string degree;
}; 

#endif
