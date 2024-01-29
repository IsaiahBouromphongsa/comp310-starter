#include <stdio.h>

int main(int argc, char *argv[]) {
    // Iterate through command-line arguments
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
