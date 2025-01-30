#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void case_text(char* filename, int p, int v) {
    int fd = open(filename, O_RDWR, 0644);
    if (fd < 0)
    {
        printf("Error opening file\n");
        return;
    }

    //lseek to find and modify the desired position
    int current_pos = 0;
    int start_offset = 0;
    char c;

    //find position
    while (read(fd, &c, 1) == 1)
    {
        if (c == ',')//when we find a coma it means we get to the stat of a new integer
        {
            if (current_pos == p)
            {
                break;//Get out of the while when we find the position
            }
            start_offset = lseek(fd, 0, SEEK_CUR);
            current_pos++;
        }
    }


    if (current_pos != p){
        printf("Error");
        return;
    }

    //move the cursor to the start offset (after the coma)
    lseek(fd, start_offset, SEEK_SET);

    //save the old text
    char temp[4096];
    int temp_len = read(fd, temp, sizeof(temp));
    temp[temp_len] = '\0';

    // Find the next comma or end of line
    int length_curr_item = 0;
    while(length_curr_item < temp_len && temp[length_curr_item] != ',' && temp[length_curr_item] != '\n')
    {
	length_curr_item++;
    }
    // Create the new value string
    char new_value[12];
    int new_value_len = sprintf(new_value, "%d", v);
    //move to the start of between comas and overwritte
    lseek(fd, start_offset, SEEK_SET);
    write(fd, new_value, new_value_len);
    //ensure that the content after the replaced valueis preserved and rewritten into the file after the new value
    if (length_curr_item < temp_len) {
        write(fd, temp + length_curr_item, temp_len - length_curr_item);
    }

    //truncate the file if needed
    int new_file_size = start_offset + new_value_len + (temp_len - length_curr_item);
    ftruncate(fd, new_file_size);

    printf("Successfully changed the value\n");
    close(fd);
}

void case_binary(char* filename, int p, int v) {
    int fd = open(filename, O_RDWR);
    if (fd < 0) {
        printf("Error opening file\n");
        return;
    }

    // Calculate the offset based on the position (each integer is 4 bytes)
    off_t offset = p * sizeof(int);

    // Seek to the correct position in the file
    if (lseek(fd, offset, SEEK_SET) == (off_t)-1) {
        printf("Error seeking in file\n");
        close(fd);
        return;
    }

    // Write the new value at the calculated position
    if (write(fd, &v, sizeof(int)) != sizeof(int)) {
        printf("Error writing to file\n");
        close(fd);
        return;
    }

    printf("Successfully changed the value\n");
    close(fd);
}



int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s -binary|-text inputfile position value\n", argv[0]);
        return 0;
    }

    char *mode = argv[1];
    char *file = argv[2];
    int position = atoi(argv[3]);
    int value = atoi(argv[4]);

    if (strcmp(mode, "-text") == 0) {
        case_text(file, position, value);
    } else if (strcmp(mode, "-binary") == 0) {
        case_binary(file, position, value);
    } else {
        printf("Invalid mode. Use -binary or -text.\n");
    }

    return 0;
}