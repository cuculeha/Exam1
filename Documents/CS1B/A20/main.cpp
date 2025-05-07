#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

const long long SIZE = 1000;

void readFile(long long *array1, long long *array2);
void selectionSort(long long list[]);
long long linearSearch (long long list1[], long long target);
long long binarySearch (long long list2[], long long target);
char showMenu (long long target, long long linear, long long binary);
long long getTarget();

int main(){

	long long *array1, *array2;
	array1 = new long long[SIZE];
	array2 = new long long[SIZE];
	char choice;
	long long target = -999;
	long long linearComparison = -1;
	long long binaryComparison = -1;

	system ("clear");
	if (array1 != nullptr && array2 != nullptr){	
		cout << "Successfully Allocated Memory of " << SIZE << " long long integers\n";
		cout << "Reading Data From A File....\n";
		readFile (array1, array2);
		cout << "Successfully loaded data in program....Press Enter to Continue..\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}



	do {
		choice = showMenu(target, linearComparison, binaryComparison);
		switch (choice)
		{			
			case '1':
			target = getTarget();
			break;

			case '2':
			linearComparison = linearSearch ( array1, target );
			break;

			case '3':
			selectionSort(array2);
			binaryComparison = binarySearch (array2, target);
			break;
		}

		}

	while (choice != '4');

	delete [] array1;
	delete [] array2;

return 0;
}


char showMenu (long long target, long long linear, long long binary)
{
	char choice;
	system("clear");
	cout << "┌───────────────────────────────────────────────────┐\n";
	cout << "│    Current Target : " << setw (30) << left << target << "│\n";
	cout << "│─────────────────Search Comparisons────────────────│\n";
	cout << "│    Linear         : " << setw (30) << left << linear << "│\n";
	cout << "│    Binary         : " << setw (30) << left << binary << "│\n";
	cout << "├───────────────────────────────────────────────────┤\n";
	cout << "│      <1> Enter integer to search                  │\n";
	cout << "│      <2> Linear Search                            │\n";
	cout << "│      <3> Binary Search                            │\n";
	cout << "│      <4> QUIT                                     │\n";
	cout << "└───────────────────────────────────────────────────┘\n";
	

	cout << "Enter your Choice\n";
	cin.get (choice);
	cin.ignore (100, '\n');

	while (choice < '1' || choice > '4' )
		{
			cout << choice << " is not a valid option. Please enter a number between 1 and 4.\n";
			cin.get (choice);
			cin.ignore (100, '\n');
		}

	return choice;
}


void readFile(long long *array1, long long *array2)
{
	long long trash;

	ifstream inData;
	inData.open ("data/1000.dat");
	int i = 0;

	// First number is not data, just an indicator.
	// The value is not to be used in program later
	inData >> trash;

	while (i < SIZE) {
	inData >> array1[i];
	array2[i]=array1[i];
	i++;

	}

	inData.close();

}

void selectionSort(long long list2[])
{
		long long index;
		long long smallestIndex;
		long long location;
		long long temp;
		for (index = 0; index < SIZE - 1; index++)
			{
					//Step a
							smallestIndex = index;
							for (location = index + 1; location < SIZE; location++){
							if (list2[location] < list2[smallestIndex])
						smallestIndex = location;
						}
							//Step b
							temp = list2[smallestIndex];
							list2[smallestIndex] = list2[index];
							list2[index] = temp;
		}
}

long long getTarget()
{
	long long target;
	system("clear");
	cout << "Enter your target to search later in the program\n";
	cin >> target;
	cin.ignore (100, '\n');

	return target;
}

long long linearSearch (long long list1[], long long target)
{
	long long loc;
	bool found = false;
	loc = 0;
	long long comparisonCount = 0;

			while (loc < SIZE && !found){
						if (list1[loc] == target)
						found = true;

						else{
							loc++;
							comparisonCount++;
					}
		}

		if (found){
		system("clear");
		cout << "Target FOUND in the list\n";
		cout << "Press Enter to Continue..\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return comparisonCount + 1;
		}

		else
		system("clear");
		cout << "Target is NOT found in the list\n";
		cout << "Press Enter to Continue..\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return -1;
}

long long binarySearch (long long list2[], long long target)
{
	long long first = 0;
	long long last = SIZE - 1;
	long long mid;
	long long binaryCount = 0 ;
	bool found = false;
			while (first <= last && !found)
				{
						mid = (first + last) / 2;
						if (list2[mid] == target)
							found = true;

						else if (list2[mid] > target){
							last = mid - 1;
							binaryCount++;
							}

						else{
							first = mid + 1;
							binaryCount++;
							}
				}

		if (found){
		system("clear");
		cout << "Target FOUND in the list\n";
		cout << "Press Enter to Continue..\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return binaryCount + 1;
		}

		else
		system("clear");
		cout << "Target is NOT found in the list\n";
		cout << "Press Enter to Continue..\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return -1;
}
