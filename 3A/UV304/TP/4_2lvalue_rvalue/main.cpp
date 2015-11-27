#include <iostream>
#include "incremental.h"
using namespace std;

int main(int argc, char* argv[]){
	Incremental a;
/*2 est un ravalue, il n'a pas de l'adresse connu*/
	cout<<"*****les rvalue :"<<endl;
	cout<<"f1 : "<<a.add1(2)<<"   f2: "<<"a.add2(2) ne marche pas, 2 est un rvalue, mais pas un lvalue (int&)"<<" f3: "<<a.add3(2)<<" f4: "<<a.add4(2)<<endl;


/*i est un lvalue, il a une adresse dans le mémoire*/
	cout<<"*****les lvalue :"<<endl;
	int i =20;
	cout<<"f1 : "<<a.add1(i)<<"   f2: "<<a.add2(i)<<" f3: "<<a.add3(i)<<" f4: "<<a.add4(std::move(i)) <<"i est un lvalue mais pas un rvalue (int&&)"<<endl;
	cout<<"f2 const à la fin de définition" <<a.add2_const(i)<<endl;


/*ci est un const lvalue */
	const int ci = 30;
	cout<<"f1 : "<<a.add1(ci)<<"   f2: "<<"a.add2(ci) ne marche pas const int != int&"<<" f3: "<<a.add3(ci)<<" f4: "<<"a.add4(std::move(ci))" <<"const int != int&& and cont int is cont, so it cannot have a referance variable, so we cannot use move to transform it to a rvalue int&& "<<endl;
}
