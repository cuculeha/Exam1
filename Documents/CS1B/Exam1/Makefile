run-test: main.cpp personType.o selectionSort.o searching.o
	g++ -std=c++20 -Wall -Werror -o run-test main.cpp personType.o selectionSort.o searching.o

personType.o: personType.cpp
	g++ -std=c++20 -Wall -Werror -c personType.cpp

selectionSort.o: selectionSort.cpp
	g++ -std=c++20 -Wall -Werror -c selectionSort.cpp

searching.o: searching.cpp
	g++ -std=c++20 -Wall -Werror -c searching.cpp

clean:
	rm out/*.o run-test
