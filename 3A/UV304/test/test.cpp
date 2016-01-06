#include <iostream>
using namespace std;
class X{
public:
	X() {cout<<"X"<<endl;}
};

int main(){
	X x();
	X y{};

	return 0;
}
