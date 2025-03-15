#include <iostream>
#include <algorithm>
#include "selectionSort.h"
#include "personType.h"
using namespace std;


// Sorts personType based on first name	
void selectionSort ( personType array[], int length)
{
	personType temp;
	int startScan;
	int minIndex;
	string minString;      // can change based on what r we sorting on
	
		for (startScan = 0; startScan < length -1 ; startScan ++ )
			{
				minIndex = startScan;
				minString = array[startScan].getFullName();


				for (int i = startScan + 1 ; i < length ; i++)
					{
						if (array[i].getFullName() < minString)
						{
						minIndex = i;
						minString = array[i].getFullName ();
						}
					}

				temp =  array[startScan];
				array[startScan] = array [minIndex];
				array[minIndex] = temp;
			}
}
