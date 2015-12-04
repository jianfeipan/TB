all: hello
hello: main.cpp Widget.o Button.o Slider.o Window.o
	g++ -Wall -std=c++11 -o hello main.cpp Widget.o Button.o Slider.o Window.o

Widget.o: Widget/Widget.cpp 
	g++ -Wall -std=c++11 -c Widget/Widget.cpp 

Button.o: Button/Button.cpp 
	g++ -Wall -std=c++11 -c Button/Button.cpp

Slider.o: Slider/Slider.cpp 
	g++ -Wall -std=c++11 -c Slider/Slider.cpp 

Window.o: Window/Window.cpp
	g++ -Wall -std=c++11 -c Window/Window.cpp
clean:
	rm *.o hello
