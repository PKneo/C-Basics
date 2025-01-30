#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>

//List in the standard output all the files and subfiles
void readRecursive(DIR* dir, char * path) {
    struct dirent* fileInDir;
    while( (fileInDir = readdir(dir)) != NULL) {
        if (fileInDir == NULL) {
            return;
        }
        else if(fileInDir->d_type == DT_DIR) {
            if (strcmp(fileInDir->d_name, ".") != 0 &&
                    strcmp(fileInDir->d_name, "..") != 0) {
                printf("Opening directory %s\n", fileInDir->d_name);
                /* 
                Done after class, I realised that you need to update the path of each file/folder,
                since the data returned in the dirent is local to the opened directory, whereas I need to 
                give the path from the current directory in which the program was executed to open a new file.
                */
                char * newPath = malloc(strlen(path) + strlen(fileInDir->d_name) + 2); // 
                strcpy(newPath, path); 
                strcat(newPath, "/"); // Concatenate with a / (in python it would be) newPath = path + "/" +  fileInDir->d_name
                strcat(newPath, fileInDir->d_name);
                readRecursive(opendir(newPath), newPath);
                free(newPath);
            }
        }
        else if (fileInDir->d_type == DT_REG) {
            char * newPath = malloc(strlen(path) + strlen(fileInDir->d_name) + 2);
            strcpy(newPath, path); 
            strcat(newPath, "/");
            strcat(newPath, fileInDir->d_name);

            printf("File %s\n", newPath);
            free(newPath);
        }
    }
}

int main(int argc, char *argv[]) {
    char * filename = argv[1];
    DIR* d = opendir(filename);
    readRecursive(d, ".");
}