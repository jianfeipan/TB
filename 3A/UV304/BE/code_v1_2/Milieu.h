#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <vector>
#include <memory>



class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<std::shared_ptr<Bestiole>>   listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( const std::shared_ptr<Bestiole> b ) { listeBestioles.push_back(b); listeBestioles.back()->initCoords(width, height); }
   int nbVoisins( const Bestiole & b );

};


#endif
