#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char s[100];
    int nBytesRead;
    //Before read s:
    // [\0\0\0\0\0\0\0\0\0\0\0\0\0\0]
    nBytesRead = read(0, s, 2); //write adsa in memory
    s[nBytesRead] = '\0';
    printf("I have read %d bytes\n", nBytesRead);
    // [adsa\n\0\0\0\0\0\0\0\0\0]

    write(1,s, strlen(s));
    printf("\nFirst line read\n\n");

    nBytesRead = read(0, s, 2); // write 1
    s[nBytesRead] = '\0';
    printf("I have read %d bytes\n", nBytesRead);

    // [1\nsa\n\0\0\0\0\0\0\0\0\0]

    write(1,s, strlen(s));

}