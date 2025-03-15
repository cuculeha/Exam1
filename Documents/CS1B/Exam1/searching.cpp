#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "personType.h"
#include "searching.h"

using namespace std;

int seqSearch (const personType list[], string target)
{
	int index = 0;
	char choice;
	string targetCopy = convertUpperCase (target);
	string arrayCopy;

	while (index < 20 )
		{
			// convert to uppercase
			arrayCopy = convertUpperCase(list[index].getFullName());

			if (arrayCopy.find(targetCopy) != string::npos)
				{
					cout << "Match : " << list[index].getFullName();
					cout << "\nIs this you want to search for ?(y/n)\n";
					cin.get(choice);
					cin.ignore (100, '\n');

					while (toupper(choice) != 'N' && toupper(choice) != 'Y' )
							{
								cout << choice << " is invalid choice.. Only enter Y or N.\n";
								cin.get (choice);
								cin.ignore (100, '\n');
							}

							if (toupper(choice) == 'Y')
								{
									return index;
								}
				}

			index++;;		
		}
	cout << "Reached end of the list, no matches found\n";
	return -1;
}

size_t tallestPerson (const personType array[] )
{
	// make the smallest as the first index
	size_t tallest = array[1].getHeight();
	int index = 1;
	size_t found;

		while (index < 20)
			{
				if (array[index].getHeight() > tallest )
					{
						tallest = array[index].getHeight();
						found = index;
					}

				index++;


			}
	return found;
}


size_t shortestPerson (const personType array[] )
{
	// make the smallest as the first index
	size_t shortest = array[1].getHeight();
	int index = 1;
	size_t found;

		while (index < 20)
			{
				if (array[index].getHeight() < shortest )
					{
						shortest = array[index].getHeight();
						found = index;
					}

				index++;


			}
	return found;
}

string convertUpperCase (string toMake)
{
	string copy = toMake;
	transform (copy.begin(), copy.end(), copy.begin(), :: toupper );

	return copy;
}
