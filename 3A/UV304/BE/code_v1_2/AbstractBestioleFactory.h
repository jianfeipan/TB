#ifndef _ABSTRACTBESTIOLEFACTORY_
#define _ABSTRACTBESTIOLEFACTORY_

#include "Bestiole.h"
#include <memory>

class AbstractBestioleFactory
{
	public :	  
 		virtual std::shared_ptr<Bestiole> createGregaire(void) =0; 
		virtual std::shared_ptr<Bestiole> createPeureuse(void) =0; 
		virtual std::shared_ptr<Bestiole> createSchizophene(void) =0; 
};
#endif
