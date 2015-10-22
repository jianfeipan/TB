#include <stdlib.h>

extern char** environ;
void main() {
	int i = 0;
	while(environ[i]){
		printf("%s\n",environ[i++]);	
	}
}
