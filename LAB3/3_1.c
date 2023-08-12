#include <stdio.h>

int binary_search_leftmost(int arr[], int size, int key, int *comparisons) {
    int left = 0, right = size - 1;
    int position = -1;  // Initialize the position to -1 (not found)
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        
        if (arr[mid] == key) {
            position = mid;
            right = mid - 1;  // Move left to continue searching for the leftmost appearance
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return position;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int key;
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    // Sort the array in case it's not already sorted
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Binary search
    int comparisons = 0;
    int position = binary_search_leftmost(arr, size, key, &comparisons);

    // Output
    if (position != -1) {
        printf("%d found at index position %d\n", key, position);
    } else {
        printf("%d not found in the array\n", key);
    }
    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
