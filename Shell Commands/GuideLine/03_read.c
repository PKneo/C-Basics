#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    printf("The read number is %d\n", n);

    char s[100];
    read(0, s, 100);
    printf("The read number is %s\n", s);
    sscanf(s, "%d", &n);
    printf("The double of the read number is %d\n", n *2);
}