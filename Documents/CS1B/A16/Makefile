run-test: main.cpp personType.o
	g++ -std=c++20 -Wall -Werror -o run-test main.cpp personType.o

personType.o: personType.cpp
	g++ -std=c++20 -Wall -Werror -c personType.cpp

clean:
	rm -f out/*.o run-test
