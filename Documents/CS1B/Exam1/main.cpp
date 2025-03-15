#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "personType.h"
#include "selectionSort.h"
#include "searching.h"
using namespace std;
char showMenu ();

int main ()
{
  personType person[20];
  
  string stringtoInput;
  double doubletoInput;
  char chartoInput;
  
  for (int i =0 ; i < 20; i ++)
    {
      cout << "Input information for personType object [" << i + 1 <<"]\n";
      cout << "Full Name  : ";
      getline (cin, stringtoInput);
      person[i].setFullName (stringtoInput);

      cout << "Address   : ";
      getline (cin, stringtoInput);
      person[i].setAddress (stringtoInput);

      cout << "Height : ";
      cin >> doubletoInput;
      person[i].setHeight (doubletoInput);
      cin.ignore();
      
      cout << "DOB    : ";
      getline (cin, stringtoInput);
      person[i].setDOB (stringtoInput);
      
      cout << "Gender  : ";
      cin.get (chartoInput);
      person[i].setGender (chartoInput);
      cin.ignore (100, '\n');

    }
  char choice;
	string target;
	int result;
	size_t height;

	do {
				choice = showMenu();

				switch (choice)
					{
						case '1':
						cout << "Keyword to Search : ";
						getline (cin, target);
						result = seqSearch (person, target);
						if (result == -1)
						{
							cout << "Press Enter to Continue..\n";
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}

						else {
						person[result].print();
						cout << "Press Enter to Continue..\n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						break;

						case '2':
						cout << "The tallest person Information\n";
						height = tallestPerson(person);
						person[height].print();
						cout << "Press Enter to Continue..\n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
						
						case '3':
						cout << "The shortest person Information\n";
						height = shortestPerson(person);
						person[height].print();
						cout << "Press Enter to Continue..\n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
						
						case '4':
						selectionSort(person, 20);
						cout << "Person names after sorting\n";
						for (	int i =0; i < 20 ; i++)
						{	
							cout << person[i].getFullName() << endl;
						}
						cout << "Press Enter to Continue..\n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;

						case '5':
						return 0;
						break;
					}
		}

	while (choice != 4);
	
 // print all information

  return 0;
}


char showMenu ()
{
char choice;
	system ("clear");
	cout << "(1)  Search for a person\n";
	cout << "(2)  Tallest person\n";
	cout << "(3)  Shortest person\n";
	cout << "(4)  Sort Persons\n";
	cout << "(5)  Quit\n";
	cout << "Enter your choice.. Only enter (1-5)\n";

	cin.get (choice);
	cin.ignore (100, '\n');
	while (choice < '1' || choice > '5' )
	{
		cout << choice << " is not a valid option. Please enter a number between 1 and 5 based on the menu.\n";
		cin.get (choice);
		cin.ignore (100, '\n');
	}


	return choice;
}
