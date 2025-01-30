#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char*argv[]) {
    int fd;
    char s[100];
    int nBytesRead;
    fd = open("Data/file.txt", O_WRONLY | O_CREAT, 0644);
    for (int i = 0; i < 100; i++) {
        if (i != 0) {
            char c = ',';
            write(fd, &c, 1);
        }
        sprintf(s, "%d", i);
        write(fd, s, strlen(s));
    }

}