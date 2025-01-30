#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd;
    fd = open("input.txt", O_RDONLY);  // Open the file in read-only mode
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    char *s = malloc(1);  // Start with a small buffer
    int buffer_size = 1;  // Initial buffer size
    int i = 0;
    int j = 0;
    char ch;
    
    while (read(fd, &ch, 1) > 0) {  // Read one byte at a time until end of file
        // Check if there's enough space in the buffer for the next character
        if (j >= buffer_size - 1) {
            buffer_size *= 2;  // Double the buffer size
            s = realloc(s, buffer_size);  // Reallocate memory for the buffer
            if (s == NULL) {
                perror("Memory allocation error");
                close(fd);
                return 1;
            }
        }
        
        s[j] = ch;  // Store the character
        j++;
        
        if (ch == ',') {  // If a comma is encountered, terminate the string
            s[j - 1] = '\0';  // Replace comma with null terminator
            printf("%s\n", s);  // Print the string
            j = 0;  // Reset the index for the next "line"
        }
    }

    // If there's any remaining string (in case the file doesn't end with a comma)
    if (j > 0) {
        s[j] = '\0';
        printf("%s\n", s);
    }

    // Clean up
    free(s);
    close(fd);

    return 0;
}
