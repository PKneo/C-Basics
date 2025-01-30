#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char*argv[]) {
    int fd;
    char s[100];
    int nBytesRead;
    fd = open("Data/binary_file.data", O_RDONLY, 0644);
    int n;

    /*
    char * s2 = malloc(20 * sizeof(int));
    read(fd, s2, 20 * sizeof(int));
    */
    int idx = lseek(fd, 40 * sizeof(int), SEEK_SET);
    while (read(fd, &n, sizeof(n)) > 0) {
        printf("%d\n", n);
        lseek(fd, 2 * sizeof(int), SEEK_CUR);
    }
       
}