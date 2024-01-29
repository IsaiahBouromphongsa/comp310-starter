#include <stdio.h>

int main() {
    const char* filename = "example.txt";

    // Writing to a file
    FILE* fileWrite = fopen(filename, "w");
    if (fileWrite == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    fprintf(fileWrite, "Hello, World!");
    fclose(fileWrite);

    // Reading from a file
    FILE* fileRead = fopen(filename, "r");
    if (fileRead == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fileRead) != NULL) {
        printf("%s", line);
    }

    fclose(fileRead);

    return 0;
}
