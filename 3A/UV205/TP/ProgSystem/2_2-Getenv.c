#include <stdlib.h>



void main(int argc, char **argv) {
  if (argc < 2){
    printf("input error");
  }else{
    printf("%s",getenv(argv[1]));
  }
}
