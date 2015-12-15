main : main.cpp Aquarium.o Bestiole.o Milieu.o BestioleFactory.o Gregaire.o Peureuse.o Schizophrene.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o BestioleFactory.o Gregaire.o Peureuse.o Schizophrene.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

BestioleFactory.o : BestioleFactory.h BestioleFactory.cpp
	g++ -Wall -std=c++11  -c BestioleFactory.cpp -I .

Gregaire.o : Gregaire/Gregaire.cpp Gregaire/Gregaire.h
	g++ -Wall -std=c++11  -c Gregaire/Gregaire.cpp -I .

Peureuse.o : Peureuse/Peureuse.cpp Peureuse/Peureuse.h
	g++ -Wall -std=c++11  -c Peureuse/Peureuse.cpp -I .

Schizophrene.o : Schizophrene/Schizophrene.cpp Schizophrene/Schizophrene.h
	g++ -Wall -std=c++11  -c Schizophrene/Schizophrene.cpp -I .

clean: 
	rm *.o main

