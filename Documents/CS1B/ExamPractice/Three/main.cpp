#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

const int TOTAL_BOOKS = 10;
const int PAGE_SIZE = 5;

// Book structure
struct Book {
    string title;
    string isbn;
    string author;
    string publisher;
    string dateAdded;
    int qty;
    double wholesaleCost;
    double retailPrice;
};
// Function to disable buffering (so arrow keys can be read instantly)
void enableRawMode() {
    struct termios new_settings;
    tcgetattr(STDIN_FILENO, &new_settings);
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}

// Function to restore terminal settings
void disableRawMode() {
    struct termios new_settings;
    tcgetattr(STDIN_FILENO, &new_settings);
    new_settings.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}


void displayBooks(Book books[], int totalBooks) {
   int startIndex = 0;
	char ch;
	enableRawMode();

    do {
			
        // Clear screen (Linux/macOS: "clear")
        system("clear");

        // Display Header
        cout << "*********************************************\n";
        cout << "*          SERENDIPITY BOOKSELLERS          *\n";
        cout << "*********************************************\n\n";

        // Print book details for current page
        for (int i = startIndex; i < startIndex + PAGE_SIZE && i < totalBooks; ++i) {
            cout << i + 1 << ". " << books[i].title << " | ISBN: " << books[i].isbn
                 << " | Author: " << books[i].author << " | Price: $" << books[i].retailPrice << "\n";
        }

      cout << "\nPage " << (startIndex / PAGE_SIZE) + 1 << " of " << (totalBooks + PAGE_SIZE - 1) / PAGE_SIZE;
		cout << "Press arrow keys (Esc to exit)...\n";

    	while (true) {
        read(STDIN_FILENO, &ch, 1); // Read a single character

        if (ch == 27) {  // Escape sequence starts with 27 (ESC key)
            char seq[2];
            read(STDIN_FILENO, &seq[0], 1);
            read(STDIN_FILENO, &seq[1], 1);

            if (seq[0] == '[') { // Arrow key sequence starts with "["
                switch (seq[1]) {
                    case 'A': cout << "Invalid arrow\n"; break;
                    case 'B': cout << "Invalid arrow\n"; break;
                    case 'C': cout << "Right arrow\n"; 
							if (startIndex + PAGE_SIZE < totalBooks)
							{
								startIndex += PAGE_SIZE;  // Move forward
							}
							break;
                    case 'D': cout << "Left arrow\n";
							if (startIndex - PAGE_SIZE >= 0)
							{
								 startIndex -= PAGE_SIZE;
							}
							break;
                };
            }
        }
	}
} while (ch != 'q');

    disableRawMode();
}


int main() {
    // Define books as an array
    Book books[TOTAL_BOOKS] = {
        {"Star Wars", "0345206791", "George Lucas", "Del Rey", "10/18/2017", 5, 59.95, 100.00},
        {"The Empire Strikes Back", "034529209X", "George Lucas", "Ballantine", "04/01/2017", 2, 179.58, 185.00},
        {"Splinter of the Mind's Eye", "0345320239", "George Lucas", "Del Rey", "11/08/2017", 3, 24.00, 26.50},
        {"Return of the Jedi", "0345307674", "George Lucas", "Del Rey", "10/09/2017", 4, 2.94, 6.50},
        {"Heir to the Empire", "0553296124", "Timothy Zahn", "Bantam", "11/01/2017", 10, 25.38, 27.00},
        {"Dark Force Rising", "0553560719", "Timothy Zahn", "Bantam", "11/08/2017", 10, 25.38, 27.00},
        {"The Last Command", "0553564927", "Timothy Zahn", "Bantam", "11/02/2017", 10, 14.30, 17.00},
        {"Specter of the Past", "0553298046", "Timothy Zahn", "Bantam", "11/08/2017", 5, 13.66, 15.00},
        {"Vision of the Future", "0553578790", "Timothy Zahn", "Bantam", "11/06/2017", 5, 10.85, 15.00},
        {"Battlestar Galactica", "185286088X", "Glen A.;Thurst", "Titan Books", "11/08/2015", 5, 102.04, 150.00}
    };

    displayBooks(books, TOTAL_BOOKS);
    return 0;
}
