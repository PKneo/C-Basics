#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char*argv[]) {
    int fd;
    char s[100];
    int nBytesRead;
    fd = open("Data/binary_file.data", O_WRONLY | O_CREAT, 0644);
    for (int i = 0; i < 100; i++) {
        write(fd, &i, sizeof(i));
    }
}