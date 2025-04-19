#include <iostream>
#include "selectionSort.h"
#include "courseType.h"
#include "personType.h"
#include "studentType.h"
#include "professorType.h"
#include <string>

using namespace std;

void setColour ( int colourCode )
{
	cout << "\033[1;" << colourCode << "m";
	return;
}


void resetColour()
{
    cout << "\033[0m"; 
}
