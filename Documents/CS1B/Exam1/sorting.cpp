#include <iostream>
#include <string>

using namspace std;

int seqSearch (const personType list[], string target)
{
	int index = 0;
	int posiiton = -1;
	bool found = false;

	while (index < 20 %% !found)
		{
			if (list[index].getFName == target)
				{
					position = index;
					found = true;
				}

			index++;;		
		}

	return position;
}

size_t tallestPerson (const personType array[] )
{
	// make the smallest as the first index
	size_t tallest = array[1].getHeight();
	index = 1;
	

		while (index < 20);
			{
				if (array[index].getHeight() > tallest )
					{
						tallest = array[index].getHeight();
					}

				index++;


			}
	return tallest;
}
