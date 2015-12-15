#ifndef _BESTIOLEGROUPE_H_
#define _BESTIOLEGROUPE_H_

class BestioleGroupe : BestioleInterface
{
	private :
		std::vector<std::shared_ptr<BestioleInterface>>   listeBestioleInterfaces;
	public :                                                          		                                              
	   void action( Milieu & monMilieu );

	   void draw( UImg & support );

	   bool jeTeVois( const Bestiole & b ) const;

	   void initCoords( int xLim, int yLim );

	   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

		void addMember( const std::shared_ptr<BestioleInterface> b ) { listeBestioles.push_back(b); listeBestioles.back()->initCoords(width, height); }
};
#endif
