all: hello
hello: main.cpp incremental.o
	g++ -Wall -std=c++11 -o hello main.cpp incremental.o
incremental.o:
	g++ -Wall -std=c++11 -c incremental.cpp
clean:
	rm *.o hello 
