#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <chrono>

using namespace std;
using namespace std::chrono;

const long long SIZE = 1000000;

void readFile(long long *array1, long long *array2, long long *array3);
void selectionSort(long long list[], long long &c, long long &s);
void insertionSort (long long list[], long long &c, long long &s);
void bubbleSort (long long list[], long long &c, long long &s );
void printTime (long long totalSeconds);

int main(){

	long long *firstPtr;
	long long *secondPtr;
	long long *thirdPtr;

	long long selectionComparison = 0;
	long long selectionSwap = 0;

	long long insertionComparison = 0;
	long long insertionShift = 0;

	long long bubbleComparison = 0;
	long long bubbleSwap = 0;

	firstPtr = new long long [SIZE];
	secondPtr = new long long [SIZE];
	thirdPtr = new long long [SIZE];
	system("clear");

	cout << "┌──────────────────────────────────────────────────────────────────┐\n";
	cout << "│                    Sorting Algorithm Comparisons                 │\n";
	cout << "│                              Metrics                             │\n";
	cout << "│                          Unsorted Array                          │\n";
	cout << "│                                                                  │\n";
	

	if (firstPtr != nullptr && secondPtr != nullptr && thirdPtr != nullptr)
	{
		cout << "│ Reading in the Data ...                                          │\n";
		readFile (firstPtr, secondPtr, thirdPtr);
	}

	else{
	return 0;
	}

	// Selection Sort
	cout << "│                                                                  │\n";
	cout << "│ Calling Selection Sort ...                                       │\n";
	auto selectionStart = high_resolution_clock::now();
	selectionSort (firstPtr, selectionComparison, selectionSwap);
	auto selectionStop = high_resolution_clock::now();
	auto selectionDuration = duration_cast<seconds>(selectionStop - selectionStart);
	cout << "│        <1> Number of Comparisons - " << left << setw(30) << selectionComparison <<  "│\n";
	cout << "│        <2> Number of Swaps       - " << left << setw(30) << selectionSwap <<  "│\n";
	printTime (selectionDuration.count());

	// Insertion Sort
	cout << "│                                                                  │\n";
	cout << "│ Calling Insertion Sort ...                                       │\n";
	auto insertionStart = high_resolution_clock::now();
	insertionSort (secondPtr, insertionComparison, insertionShift);
	auto insertionStop = high_resolution_clock::now();
	auto insertionDuration = duration_cast<seconds>(insertionStop - insertionStart);
	cout << "│        <1> Number of Comparisons - " << left << setw(30) << insertionComparison <<  "│\n";
	cout << "│        <2> Number of Shifts      - " << left << setw(30) << insertionShift <<  "│\n";
	printTime (insertionDuration.count());

	// Bubble Sort
	cout << "│                                                                  │\n";
	cout << "│ Calling Bubble Sort ...                                          │\n";
	auto bubbleStart = high_resolution_clock::now();
	bubbleSort (thirdPtr, bubbleComparison, bubbleSwap );
	auto bubbleStop = high_resolution_clock::now();
	auto bubbleDuration = duration_cast<seconds>(bubbleStop - bubbleStart);
	cout << "│        <1> Number of Comparisons - " << left << setw(30) << bubbleComparison <<  "│\n";
	cout << "│        <2> Number of Swaps       - " << left << setw(30) << bubbleSwap <<  "│\n";
	printTime (bubbleDuration.count());

	cout << "│                                                                  │\n";
	cout << "│ Press any key to continue ...                                    │\n";
	cout << "└──────────────────────────────────────────────────────────────────┘\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	delete[] firstPtr;
	delete[] secondPtr;
	delete[] thirdPtr;

return 0;
}

void readFile(long long *array1, long long *array2, long long *array3)
{
	long long trash;

	ifstream inData;
	inData.open ("data/1000000.dat");
	long long i = 0;

	// First number is not data, just an indicator.
	// The value is not to be used in program later
	inData >> trash;

	while (i < SIZE) {
	inData >> array1[i];
	array2[i]=array1[i];
	array3[i]=array1[i];
	i++;

	}

	inData.close();

}

void selectionSort(long long list[], long long &c, long long &s)
{
		long long index;
		long long smallestIndex;
		long long location;
		long long temp;
		for (index = 0; index < SIZE - 1; index++)
			{
					//Step a
							smallestIndex = index;
							for (location = index + 1; location < SIZE; location++)	{
								c++;
									if (list[location] < list[smallestIndex])
										{
												smallestIndex = location;
										}
						}
							//Swapping step
							temp = list[smallestIndex];
							list[smallestIndex] = list[index];
							list[index] = temp;
							s++;
		}
}

void insertionSort(long long list[], long long &c, long long &s) {
	long long i;
	long long j;

    for (i = 1; i < SIZE; i++) {
        long long key = list[i];         // current element
        j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && list[j] > key) {   // Comparisons and Shifting happens here
            list[j + 1] = list[j];
            j--;
				c++;
				s++;
        }

			if (j >= 0) c++; // j >=  0 is a comparison too that exited the loop

        // Insert key at correct position (no comparing and swapping here)
        list[j + 1] = key;
			s++; 		// the key is swapped to be in a correct place
    }
}

void bubbleSort (long long list[], long long &c, long long &s)	{

long long i;
long long j;
long long temp;
	for (i = 0; i < SIZE; i++) {

   	for (j = SIZE -1 ; j >= i + 1; j--) {
			c++;
        if (list[j] < list[j-1]) {
				// Swap the elements
				temp = list[j];
				list[j]= list[j-1];
				list[j-1] = temp;
				s++;
           }
   	 }
	}

}


void printTime (long long totalSeconds)
{
	long long hours = totalSeconds / 3600;
   long long minutes = (totalSeconds % 3600) / 60;
   long long seconds = totalSeconds % 60;

    string time = "";

    if (hours > 0)
        time += to_string(hours) + " hr, ";

    if (minutes > 0 || hours > 0)
        time += to_string(minutes) + " min, ";

    time += to_string(seconds) + " sec";

	cout << "│        <3> Time Taken            - " << left << setw(30) << time <<  "│\n";
	
}
