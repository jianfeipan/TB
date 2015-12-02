all: hello

hello: main.cpp Point.o PointFactory.o Polygon.o 
	g++ -Wall -std=c++11 -o hello main.cpp Point.o PointFactory.o Polygon.o

Point.o: Point.cpp 
	g++ -Wall -std=c++11 -c Point.cpp

PointFactory.o:PointFactory.cpp
	g++ -Wall -std=c++11 -c PointFactory.cpp

Polygon.o:
	g++ -Wall -std=c++11 -c Polygon.cpp

Compare.o:
	g++ -Wall -std=c++11 -c Compare.cpp

clean:
	rm *.o hello

