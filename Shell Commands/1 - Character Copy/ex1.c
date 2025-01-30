#include <unistd.h>
#include <stdio.h>

int main(int argc, char* agrv[]){
  int fd = 0; 
  char c;
  read(0,&c,1);
  printf("Character typed: %c\n", c);
  
  return 0;
}