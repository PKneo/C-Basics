#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Function 1: text_to_binary
void text_to_binary(const char *inputfile, const char *outputfile) {
    int infd = open(inputfile, O_RDONLY); // Open input file in read-only mode

    // Error Handling
    if (infd < 0) {
        printf("Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    int outfd = open(outputfile, O_WRONLY | O_CREAT | O_TRUNC, 0644); // Open output file in write-only mode

    // Error Handling
    if (outfd < 0) {
        printf("Error opening output file\n");
        close(infd);
        exit(EXIT_FAILURE);
    }

    //char buffer[4096];
    char ch;
    
    // Read the input file one byte at a time
    while (read(infd, &ch, 1) > 0) {

        int a = atoi(&ch);

        printf("Byte to be written: ");
        for (int i = 7; i >= 0; i--) { // 8 bits in a char
        // Print each bit (either 0 or 1)
            putchar((a & (1 << i)) ? '1' : '0');
        }
        write(outfd, &a, sizeof(int));
        printf(" ");  // Space between each byte's binary representation
        printf("\n");


        // Write the binary data to the output file (each character as a byte)
    }

    // Clean up
    close(infd);
    close(outfd);
}



// Function 2: binary_to_text
void binary_to_text(const char *inputfile, const char *outputfile) {
    // Open the input 
    int infd = open(inputfile, O_RDONLY);

    //Error Handling
    if (infd < 0) {
        printf("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output
    int outfd = open(outputfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);


    //Error Handling
    if (outfd < 0) {
        printf("Error opening output file");
        close(infd); 
        exit(EXIT_FAILURE);
    }

    // Size to read
    int n;
    char buffer[1];
    int offset = 0;

    while (read(infd, &n, sizeof(n)) > 0) {
        sprintf(buffer, "%d", n);
        if (n == 0){
            write(outfd, ",", 1);
        }
        else{
        write(outfd, buffer, strlen(buffer));
        }
        printf("%d\n", n);
    }

    // Close the files
    close(infd);
    close(outfd);
}

// Main function
int main(int argc, char *argv[]) {
    // Handle argc
    if (argc != 4) {
        printf("Usage: %s -binary|-text inputfile outputfile\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Define each argument
    char * type = argv[1];
    char * infd = argv[2];
    char * outfd = argv[3];

    // Determine if it's an input type of bin or txt
    if (strcmp(type, "-binary") == 0) {
        binary_to_text(infd, outfd);
    } 

    else if (strcmp(type, "-text") == 0) {
        text_to_binary(infd, outfd);
    } 

    else {
        printf("Error: Invalid type '%s'.\n", type);
        printf("Usage: %s -binary|-text inputfile outputfile\n", argv[0]);
        return EXIT_FAILURE;
    }

    // End
    printf("Conversion successful: %s -> %s\n", infd, outfd);
    return EXIT_SUCCESS;
}
