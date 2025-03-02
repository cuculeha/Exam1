#include <iostream>
#ifndef PERSONTYPE_H
#include "personType.h"
#endif

using namespace std;

int main (){
	string names;

	// Default constructor will execute
	personType person1;

	// Constructor with first name and second name initializes
	personType person2 ("Bob", "Thompson");

	// Constructor with all members initialized
	personType person3 ("Sarah", "Hampton", "800 Calle Vaquero San Clemente, 92672", 'F', "03/14/1980", 60.8);

	//Finish populating persons with data
	person1.setFName ("Brian");
	person1.setLName ("Skyler");
	person1.setAddress ("456 Ocean Drive, Miami, FL 33139");
	person1.setHeight (70);
	person1.setDOB ("08/09/1978");
	person1.setGender ('M');

	person2.setAddress ("Shibuya Scramble Square, Tokyo, Japan 150-0002");
	person2.setHeight (67.6);
	person2.setDOB ("06/11/2005");
	person2.setGender ('M');

	// Print the persons
	cout << "Person 1 details using default constructor\n";
	person1.print();
	
	cout << "Person 2 using constructor with first and last name passed\n";
	person2.print();
	
	cout << "Person 3 using constructor with all passed data members\n";
	person3.print();

return 0;
}
