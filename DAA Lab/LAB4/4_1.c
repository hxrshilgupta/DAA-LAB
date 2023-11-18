#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to perform the merge step of Merge Sort
void merge(int arr[], int left, int mid, int right, long long *comparisons)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        (*comparisons)++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right, long long *comparisons)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);

        merge(arr, left, mid, right, comparisons);
    }
}
int main()
{
    int option, n;
    FILE *inputFile, *outputFile;

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n2. Descending Data\n3. Random Data\n4. EXIT\n");
    printf("Enter option: ");
    scanf("%d", &option);

    if (option < 1 || option > 4)
    {
        printf("Invalid option. Exiting...\n");
        return 0;
    }

    char *inputFileName, *outputFileName;

    switch (option)
    {
    case 1:
        inputFileName = "inAsce.dat";
        outputFileName = "outMergeAsce.dat";
        break;
    case 2:
        inputFileName = "inDesc.dat";
        outputFileName = "outMergeDesc.dat";
        break;
    case 3:
        inputFileName = "inRand.dat";
        outputFileName = "outMergeRand.dat";
        break;
    case 4:
        printf("Exiting...\n");
        return 0;
    }

    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
        fscanf(inputFile, "%d", &arr[i]);

    fclose(inputFile);

    long long comparisons = 0;

    clock_t start_time = clock();

    mergeSort(arr, 0, n - 1, &comparisons);

    clock_t end_time = clock();

    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1e9; // Convert to nanoseconds

    printf("Before Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    outputFile = fopen(outputFileName, "w");

    if (outputFile == NULL)
    {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        fprintf(outputFile, "%d ", arr[i]);

    fclose(outputFile);

    printf("After Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Number of Comparisons: %lld\n", comparisons);
    printf("Execution Time: %.2f nanoseconds\n", execution_time);
    printf("\nHarshil Gupta");
    printf("\n2105889");
    printf("\nCSE 32");
    return 0;
}
