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
	pointer[1] = new professorType ("Robert", "Elijah");
	professorType* professor = dynamic_cast<professorType*>(pointer[1]);
	if (professor != nullptr )
	{
		professor->setAddress ("123 Alicia Pkwy");
		professor->setGender ('M');
		professor->setDOB ("06/30/1980");
		professor->setEmpID ("E83434");
		professor->setDep ("Computer Science");
		professor->setDegree ("PhD in Computer Science");
		professor->setHeight (67.4);
	}

	// Third person (student) that has a mother of personType above and father of professorType.
	pointer[2] = new studentType ("John", "Dora");
	studentType* student = dynamic_cast<studentType*>(pointer[2]);

	if (student != nullptr)
	{
		student->setGPA (3.5);
		student->setAddress ("1234 Elm Street");
		student->setGender ('M');
		student->setDOB ("02/02/2004");
		student->setClassification ("Junior");
		student->setHeight(56);
		student->setID ("S374732");
		student->setMother (pointer[0]);
		student->setFather (pointer[1]);
	}

	cout << "-------------------------All persons information-------------------------\n";
	pointer[0]->print();
	professor->print();
	student->print();

	pointer[3] = new personType (*pointer[0]);
	pointer[3]->print();

	for (int i = 0; i < 4 ; i++)
	{
		if (pointer[i] != nullptr)
		{
		delete pointer[i];
		pointer[i] = nullptr;
		cout << "Hello\n";
		}
	}
	cout << endl;
	cout << "End of program\n";

  return 0;
}
