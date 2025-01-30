#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    printf("Hello, World, I have %d arguments!\n", argc);
    int i;
    for(i = 0; i < argc; i++){
        printf("argv[%d]: %s\n", i, argv[i]);
        if(strcmp(argv[i],"cat") == 0){
            printf("I am a cat!\n");
        }
        else{
            printf("I am not a cat!\n");
        }
    }
}