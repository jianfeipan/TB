#ifndef _BESTIOLEFACTORY_
#define _BESTIOLEFACTORY_
#include "AbstractBestioleFactory.h"

class BestioleFactory : public AbstractBestioleFactory
{
	private : 
		static std::shared_ptr<BestioleFactory> bestioleFactoryInstance ;
		BestioleFactory();
	public :
		static std::shared_ptr<BestioleFactory> factoryInstance();
		~BestioleFactory(){};	
 		std::shared_ptr<Bestiole> createGregaire(void) override; 
		std::shared_ptr<Bestiole> createPeureuse(void) override; 
		std::shared_ptr<Bestiole> createSchizophene(void) override; 
};
#endif
