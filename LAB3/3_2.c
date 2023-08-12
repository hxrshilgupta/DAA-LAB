#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n, long long int *comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArrayToFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

void readArrayFromFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

int main() {
    int choice;
    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    const char *inputFile, *outputFile;

    switch (choice) {
        case 1:
            inputFile = "inAsce.dat";
            outputFile = "outInsAsce.dat";
            break;
        case 2:
            inputFile = "inDesc.dat";
            outputFile = "outInsDesc.dat";
            break;
        case 3:
            inputFile = "inRand.dat";
            outputFile = "outInsRand.dat";
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    const int maxSize = 500;
    int arr[maxSize];
    int n;
    printf("Enter the number of elements (between 300 and 500): ");
    scanf("%d", &n);

    if (n < 300 || n > 500) {
        printf("Invalid number of elements\n");
        return 1;
    }

    readArrayFromFile(arr, n, inputFile);

    long long int comparisons = 0;
    insertionSort(arr, n, &comparisons);
    printArrayToFile(arr, n, outputFile);

    printf("Before Sorting: Content of the input file\n");
    printf("After Sorting: Content of the output file\n");
    printf("Number of Comparisons: %lld\n", comparisons);

    // Determine the scenario based on the number of comparisons
    if (comparisons == ((long long int)n * (n - 1)) / 2) {
        printf("Scenario: Best-case\n");
    } else if (comparisons == 0) {
        printf("Scenario: Worst-case\n");
    } else {
        printf("Scenario: Average-case\n");
    }

    return 0;
}