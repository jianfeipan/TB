#include "Gregaire.h"
#include <cmath>

void Gregaire::action( Milieu & monMilieu )
{	
	orientation += 0.3*M_PI;
	Bestiole::action(monMilieu);
}

