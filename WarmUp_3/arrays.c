#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int sum = 0;
    int length = sizeof(numbers) / sizeof(numbers[0]); // Calculate array length
    double average;

    for (int i = 0; i < length; i++) {
        sum += numbers[i];
    }

    average = (double)sum / length;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}
