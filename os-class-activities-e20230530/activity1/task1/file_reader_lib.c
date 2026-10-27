/* file_reader_lib.c */
#include <stdio.h>

int main() {
    // Open the file created in Part A
    FILE *fp = fopen("output.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read and display contents
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(fp);
    return 0;
}
