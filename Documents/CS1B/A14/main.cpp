#include <iostream>
#include <cstdlib>
#include "personType.h"
#include "studentType.h"
#include "professorType.h"
using namespace std;

int main ()
{
	personType *pointer[4];

	// First person with personType (will be someone's mom)
	pointer[0] = new personType("Alicia", "Mark", "821 Calle Campana", 'F', "02/03/2003", 56.7, nullptr, nullptr);

	//Second person with professorType (will be someone's dad)
	pointer[1] = new professorType ("Mr. Ali", "Huzaimah");
	professorType* professor = static_cast<professorType*>(pointer[1]);
	if (professor != nullptr )
	{
		professor->setAddress ("123 Street Somewhere in Mexico");
		professor->setGender ('M');
		professor->setDOB ("26 June 2003");
		professor->setEmpID ("E83434");
		professor->setDep ("Computer Science");
		professor->setDegree ("PhD in Computer Science");
		professor->setHeight (67.4);
	}

	// Third person (student) that has a mother of personType above and father of professorType.
	pointer[2] = new studentType ("John", "Dora");
	studentType* student = static_cast<studentType*>(pointer[2]);

	if (student != nullptr)
	{
		student->setGPA (3.5);
		student->setAddress ("123 Street Somewhere in California");
		student->setGender ('F');
		student->setDOB ("2nd July 2024");
		student->setClassification ("Junior");
		student->setHeight(56);
		student->setID ("S374732");
		student->setMother (pointer[0]);
		student->setFather (pointer[1]);
	}

	// Last person for copy constructor
	pointer[3] = new personType (*pointer[0]);

	cout << "All persons information\n";
	pointer[0]->print();
	professor->print();
	student->print();
	pointer[3]->print();

	for (int i = 0; i < 4 ; i++)
	{
		delete pointer[i];
	}

  return 0;
}
