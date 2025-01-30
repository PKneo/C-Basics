#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
/*
int main(int argc, char* argv[]){
    int fd;
    fd = open("Data/file.txt", O_RDONLY);
    char s[100];
    int i;
    for(i = 0; i< 5; i++) {
        int nBytes =  read(fd, s, 5);
        printf("Bytes read= %d \n", nBytes);
        for (int j = 0; j< 20; ++j) {
            if (s[j] == ',') {
                s[j] = '\0';
                printf("%s\n", s);
                break;
            }
        }
    }  
}
*/

int main(int argc, char* argv[]){
    int fd;
    fd = open("Data/file.txt", O_RDONLY);
    char s[100];
    int i;
    for(i = 0; i< 3; i++) {
        for (int j = 0; j < 100; ++j) {
            read(fd, &s[j], 1);
            if (s[j] == ',') {
                s[j] = '\0';
                break;
            }
        }
        printf("%s\n", s);
    }
}