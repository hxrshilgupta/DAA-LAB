#include <stdio.h>

// Function to swap/exchange elements at indices i and j in the array
void EXCHANGE(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to rotate the first p2 elements of the array to the right by 1 position
void ROTATE_RIGHT(int arr[], int p2) {
    if (p2 <= 0) {
        // Nothing to rotate, or invalid input, return
        return;
    }

    // Save the first element of the subarray to be rotated
    int saved_element = arr[p2 - 1];

    // Move all other elements one position to the right
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(arr, i, i - 1);
    }

    // Set the last element of the subarray to the saved element
    arr[0] = saved_element;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int p2;
    printf("Enter the number of elements to rotate: ");
    scanf("%d", &p2);

    ROTATE_RIGHT(arr, p2);

    printf("Array after rotation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}