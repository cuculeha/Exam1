#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include "personType.h"
#include <limits>
using namespace std;

int main ()
{
	int SIZE = 5;
	personType **arr;
	arr = new personType*[SIZE];
	cout << "Address of arr " << arr << endl;

	// Input data into the program
	for (int i = 0; i < SIZE ; i++)
	{
		arr[i] = new personType;
		cin >> *arr[i];
	}
	cout << "\nPress Enter to View the Data Entered..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//Output data from the program
	system("clear");
	cout << "Entered data...\n";
	for (int i =0; i < SIZE ; i ++)
	{
	cout << "Person [" << i+1 << "]'s data below\n";
	cout << *arr[i]; 
	cout << "-------------\n";
	}

	cout << "\nPress Enter to Continue..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system ("clear");


	cout << boolalpha;

	for (int i = 0; i < SIZE; i++) {
    cout << "Pointer *arr[" << i << "] = " << *arr[i] << "\n";

    for (int k = 0; k < SIZE; k++) {
        if (i == k) {
            cout << "  *arr[" << i << "] vs *arr[" << k << "] → SKIPPED (same)\n";
        } else {
            cout << "  *arr[" << i << "] == *arr[" << k << "] → " << (*arr[i] == *arr[k]) << "\n";
            cout << "  *arr[" << i << "] >  *arr[" << k << "] → " << (*arr[i] > *arr[k]) << "\n";
            cout << "  *arr[" << i << "] <  *arr[" << k << "] → " << (*arr[i] < *arr[k]) << "\n";
            cout << "  *arr[" << i << "] != *arr[" << k << "] → " << (*arr[i] != *arr[k]) << "\n";
        }
        cout << endl;
    }

    cout << "----------------------------------\n";
	}

	for (int i =0; i < SIZE ; i++)
	{
		delete arr[i];
	}
	delete []arr;
  return 0;
}
