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
	pointer[0] = new personType("Alicia", "Mark", "42 Maple Dr", 'F', "02/03/2003", 56.7, nullptr, nullptr);

	//Second person with professorType (will be someone's dad)
	pointer[1] = new professorType ("Robert", "Elijah");
	professorType* professor = dynamic_cast<professorType*>(pointer[1]);
	if (professor != nullptr )
	{
		professor->setAddress ("123 New York City");
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
		student->setDOB ("02/02/2010");
		student->setClassification ("Junior");
		student->setHeight(56);
		student->setID ("S374732");
		student->setMother (pointer[0]);
		student->setFather (pointer[1]);
	}

	cout << "--------------------------------All persons information--------------------------------\n";
	cout << "----------> First Person(personType) is someone's mom\n";
	pointer[0]->print();
	cout << "----------> Second Person(professorType) is someone's dad\n";
	professor->print();
	cout << "----------> Third Person(studentType) is student with mom and dad\n";
	student->print();

	cout << "----------> Fourth Person(personType) is a copy of studentType from above\n";
	pointer[3] = new personType (*pointer[2]);
	pointer[3]->print();

	cout << endl;
	if (student!=nullptr){
	student->setMother(nullptr);
	student->setFather(nullptr);
	}

	if (pointer[3]!= nullptr){
		pointer[3]->setMother(nullptr);
		pointer[3]->setFather(nullptr);
	}

	for (int i = 0; i < 4 ; i++)
	{
		if (pointer[i] != nullptr)
		{
		delete pointer[i];
		pointer[i] = nullptr;
		}
	}
	cout << "Finally.. worth the time.. End of program\n";

  return 0;
}
