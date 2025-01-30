#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
    char * s = "hello\n";
    printf(s);

    write(1, s, strlen(s));

    int n = 875770417;
    printf("%d\n", n); 
    printf("%x\n", n); 
    
    char myS[4];
    sprintf(myS, "%d", n);
    write(1, myS, strlen(myS));
    write(1, "\n", 1);
}