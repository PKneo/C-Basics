#include <stdio.h> 
#include <fcntl.h>
#include <unistd.h>

#include <sys/stat.h>//Print file size

#define FILENAME "nums.dat"
#define LENGTH 100


int main(int argc, char const *argv[])
{
    int numbers[LENGTH];
    int readNumbvers[LENGTH];

    //Open, create file and erase (truncate) content if there is any. 
    int numsfd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    //Fill file with data
    for(int i = 0; i<100; i++){
        write(numsfd, &i, sizeof(int));
    }




    // Get file statistics
    struct stat fileStat;
    if (stat(FILENAME, &fileStat) == 0) {
        printf("Size of %s: %ld bytes\n", FILENAME, fileStat.st_size);
    } else {
        perror("Error getting file size");
        return 1;
    }

}
