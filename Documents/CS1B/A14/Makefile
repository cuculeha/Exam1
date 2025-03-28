run-test: main.cpp studentType.o personType.o professorType.o
	g++ -std=c++20 -Wall -Werror -o run-test main.cpp studentType.o personType.o professorType.o

personType.o: personType.cpp
	g++ -std=c++20 -Wall -Werror -c personType.cpp

studentType.o: studentType.cpp
	g++ -std=c++20 -Wall -Werror -c studentType.cpp

professorType.o: professorType.cpp
	g++ -std=c++20 -Wall -Werror -c professorType.cpp

clean:
	rm -f out/*.o run-test
