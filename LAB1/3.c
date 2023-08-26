#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int n, i, j, count, maxCount, mostRepeating;
    int numbers[MAX_SIZE];

    // Read the value of n
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    // Open the file for reading
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read 'n' integers from the file and store them in the array
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &numbers[i]);
    }

    // Close the file
    fclose(file);

    printf("The content of the array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Find the total number of duplicate elements
    int duplicates = 0;
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (numbers[i] == numbers[j]) {
                count++;
            }
        }
        if (count > 1) {
            duplicates++;
        }
    }
    printf("Total number of duplicate values = %d\n", duplicates);

    // Find the most repeating element
    maxCount = 0;
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (numbers[i] == numbers[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostRepeating = numbers[i];
        }
    }
    printf("The most repeating element in the array = %d\n", mostRepeating);

    return 0;
}
