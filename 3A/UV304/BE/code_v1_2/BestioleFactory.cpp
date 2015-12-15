#include "BestioleFactory.h"
#include "./Gregaire/Gregaire.h"
#include "./Peureuse/Peureuse.h"
#include "./Schizophrene/Schizophrene.h"

std::shared_ptr<BestioleFactory> BestioleFactory::bestioleFactoryInstance = NULL;
 
BestioleFactory::BestioleFactory(){
}

std::shared_ptr<BestioleFactory> BestioleFactory::factoryInstance(){
	if(bestioleFactoryInstance==NULL){
		bestioleFactoryInstance.reset(new BestioleFactory());
	}
 	return bestioleFactoryInstance; 
}

std::shared_ptr<Bestiole> BestioleFactory::createGregaire(){
	std::shared_ptr<Bestiole> g(new Gregaire);
	return g;
}

std::shared_ptr<Bestiole> BestioleFactory::createPeureuse(){
	std::shared_ptr<Bestiole> p(new Peureuse);
	return p;
}

std::shared_ptr<Bestiole> BestioleFactory::createSchizophene(){
	std::shared_ptr<Bestiole> s( new Schizophrene);
	return s;
}
