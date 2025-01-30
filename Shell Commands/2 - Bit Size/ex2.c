#include <stdio.h>

int main() {
    int numbers[100]; // Declare an array of 100 integers

    // Calculate the size in bytes
    int totalSize = sizeof(numbers);
    printf("Total size of 100 integers: %u bytes\n", totalSize);

    return 0;
}
