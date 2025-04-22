#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

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


template<typename T>
T* findById(T** array, int size, string idToFind, string (T::*getIdFunc)() const) {
    for (int i = 0; i < size; ++i) {
        if (array[i] != nullptr) {
            if ((array[i]->*getIdFunc)() == idToFind) {
                return array[i];
            }
        }
    }
    return nullptr;
}

#endif

#ifndef SETCOLOUR_H
#define SETCOLOUR_H

#include <iostream>

using namespace std;

void setColour ( int colourCode );
void resetColour();
string trimString(string str, int size);

#endif
