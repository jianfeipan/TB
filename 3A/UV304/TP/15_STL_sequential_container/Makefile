all: hello
hello: main.cpp IntVector.o Point.o PointFactory.o Widget.o Button.o Slider.o Window.o
	g++ -Wall -std=c++11 -o hello main.cpp IntVector.o Point.o PointFactory.o Widget.o Button.o Slider.o Window.o

IntVector.o: IntVector.cpp
	g++ -Wall -std=c++11 -c IntVector.cpp

Point.o: Point.cpp
	g++ -Wall -std=c++11 -c Point.cpp

PointFactory.o: PointFactory.cpp
	g++ -Wall -std=c++11 -c PointFactory.cpp

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
