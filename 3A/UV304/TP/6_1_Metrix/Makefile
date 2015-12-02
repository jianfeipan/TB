all: hello

hello: main.cpp Matrix.o  
	g++ -Wall -std=c++11 -o hello main.cpp Matrix.o 

Matrix.o:
	g++ -Wall -std=c++11 -c Matrix.cpp

clean:
	rm *.o hello

