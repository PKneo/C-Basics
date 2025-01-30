#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    int fd;
    char s[100];
    int nBytesRead;
    fd = open("Data/file.txt", O_RDONLY);
    int n = 0;
    char c;
    while(nBytesRead = read(fd, &c, 1))
        n += nBytesRead;
    printf("The number of bytes in the file is %d\n", n);

    n = lseek(fd, 0, SEEK_END);
    printf("The number of bytes in the file is %d\n", n);

}