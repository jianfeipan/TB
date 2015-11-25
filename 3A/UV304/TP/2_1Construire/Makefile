all: hello

hello: main.cpp Point.o
	g++ -Wall -std=c++11 -o hello main.cpp Point.o

Point.o: Point.cpp 
	g++ -Wall -std=c++11 -c Point.cpp

clean:
	rm *.o hello

