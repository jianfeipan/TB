#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "BestioleFactory.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );
	std::shared_ptr<AbstractBestioleFactory> factory(BestioleFactory::factoryInstance());
//
   for ( int i = 1; i <= 20; ++i )
      ecosysteme.getMilieu().addMember(factory->createGregaire());
	/*ecosysteme.getMilieu().addMember(factory->createPeureuse());
	ecosysteme.getMilieu().addMember(factory->createSchizophene());*/
   ecosysteme.run();


   return 0;

}
