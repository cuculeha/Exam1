// Author      : Saliha Babar
// Assignment  : A2
// Due Date    : 01/21/2025
// Purpose     : C-Style Arrays

#include <iostream>
#include <cstddef>

using namespace std;

const int numBooks = 3;
const int maxChars = 80;

// Function to calculate string length safely
size_t stringLength (const char characters [], size_t maxChars);

int main(){
  char bookTitle[numBooks][maxChars] = {"Hello", "Saliha", "Popular Books"};
  size_t longestIndex;                     // Index of the longest index
  size_t longestString;                    // Longest string found
  size_t currentLength;                    // Length of the current string through looping

  
  longestIndex = 0;
  longestString = stringLength (bookTitle[0], maxChars);

  for (int i = 1; i < numBooks ; i++)
    {
      currentLength = stringLength (bookTitle[i], maxChars );
        if (currentLength > longestString )
      {
        longestIndex = i;
        longestString = currentLength;
      }
    }

cout << "Here is the book with longest string\n";
cout << "Element [" << longestIndex +1 << "] has the longest title which is: ";
cout << bookTitle[longestIndex] << endl;
  
return 0;
}

size_t stringLength (const char characters [], size_t maxChars)
{
  size_t length = 0;
  while (length < maxChars && characters[length] != '\0' )
    {
    length ++;
    }
return length;
}
