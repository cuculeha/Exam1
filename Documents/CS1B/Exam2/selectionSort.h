#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <string>
#include <iomanip>

template <typename T, typename Compare = std::less<T>>

void SelectionSort(T arr[], int size, Compare comp = Compare()) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (comp(arr[j], arr[minIndex])) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

template <typename S>
int searchObjectList (S** objects, int count)
{
	int position;
	cout << left << setw (3) <<"No." << left << setw (10) << "First Name " << left << setw(10) << "Last Name\n";
	
	for (int i =0; i < count ; i++)
	{
		cout << i + 1 << "-" ;
		objects[i]->print();
	}

	cout << "Choose anyone from the list above, enter your choice carefully\n";
	cout << "Enter 0 if you want to opt out\n";
	cin >> position;
	cin.ignore();

	while (position < 0 || position > count )	{
		cout << "Incorrect int input, enter again, only enter valid one\n";
		cin >> position;
		cin.ignore();
	}
	return position -1;

}
#endif

#ifndef SETCOLOUR_H
#define SETCOLOUR_H

#include <iostream>

using namespace std;

void setColour ( int colourCode );
void resetColour();

#endif
