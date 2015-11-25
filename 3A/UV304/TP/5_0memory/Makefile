all: hello

hello: main.cpp Point.o PointFactory.o
	g++ -Wall -std=c++11 -o hello main.cpp Point.o PointFactory.o

Point.o: Point.cpp 
	g++ -Wall -std=c++11 -c Point.cpp

PointFactory.o:PointFactory.cpp
	g++ -Wall -std=c++11 -c PointFactory.cpp

clean:
	rm *.o hello

