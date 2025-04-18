#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <cstdlib>
#include "personType.h"
#include "selectionSort.h"
#include <limits>
using namespace std;

int main ()
{
	int SIZE = 5;
  	personType people[SIZE];
	personType *ptrPeople[SIZE];
	int integers[] = {4,7,2,6,8,45,0, -1, 3, -14};

	cout << "Enter data for personType objects\n";
	for (int i = 0; i < SIZE; i++ )	{
		cin >> people[i];
	}

	// For the 5 pointers
	cout << "Enter data for personType pointers\n";
	for (int i = 0; i < SIZE ; i++){
		ptrPeople[i] = new personType;
		cin >> *ptrPeople[i];
	}

	// Sort people in order
	SelectionSort (people, 5);

	// Use of lambda function to access pointers in selectionsort
	SelectionSort(ptrPeople, 5, [](personType* a, personType* b) { return *a < *b;	});
	
	system ("clear");

	//Make a cout statement on all concept we worked on
	cout << "PersonType Objects sorted in Alphabetical Order (Last, First )\n";
	for (int i = 0; i < SIZE ; i++)	{
	cout << people[i];
	}

	cout << endl;

	cout << "PersonType pointers sorted in Alphabetical Order (Last, First )\n";
	for (int i = 0; i < SIZE ; i++)	{
	cout << *ptrPeople[i];
	}
	cout << endl;

	cout << "10 integers before sorting : ";
	for (int i=0; i < 10 ; i++){ 
	cout << integers[i] << " "; }

	// Sort ints in order
	SelectionSort (integers, 10);
	
	cout << "\nIntegers sorted in Ascending Order : ";
	for (int i = 0; i < 10 ; i++){
	cout << integers[i] << " ";	}
	cout << "\n\n";

	// Deallocate memory for new operator we used
	for (int i = 0; i < SIZE ; i++){	
		delete ptrPeople[i];
		ptrPeople[i] = nullptr;
	}

	return 0;
}
