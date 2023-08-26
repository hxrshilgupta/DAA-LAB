#include <stdio.h>

void findSecondSmallestAndLargest(int arr[], int n) {
    int firstSmallest, secondSmallest, firstLargest, secondLargest;

    if (n < 2) {
        printf("Array should have at least two elements.\n");
        return;
    }
    // Initialize first and second smallest/largest with first two elements
    if (arr[0] < arr[1]) {
        firstSmallest = arr[0];
        secondSmallest = arr[1];
        firstLargest = arr[1];
        secondLargest = arr[0];
    } else {
        firstSmallest = arr[1];
        secondSmallest = arr[0];
        firstLargest = arr[0];
        secondLargest = arr[1];
    }
    for (int i = 2; i < n; i++) {
        if (arr[i] < firstSmallest) {
            secondSmallest = firstSmallest;
            firstSmallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != firstSmallest) {
            secondSmallest = arr[i];
        }

        if (arr[i] > firstLargest) {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != firstLargest) {
            secondLargest = arr[i];
        }
    }
    printf("Second Smallest: %d\n", secondSmallest);
    printf("Second Largest: %d\n", secondLargest);
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    FILE *file = fopen("input1.txt", "r"); 
    // input.txt is the file name while "r" is the opening mode/accessing mode of the file, file is the File pointer
    if (file == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    findSecondSmallestAndLargest(arr, n);

    return 0;
}
