#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1, j;
    for (j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            count++;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    count++;
    return i + 1;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    int choice;
    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        FILE *in = fopen("inAsce.dat", "r");
        FILE *out = fopen("outQuickAsce.dat", "w");
        int n = 400;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(in, "%d, ", &arr[i]);
        }
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(out, "Sorted array: ");
        for (int i = 0; i < n; i++)
        {
            fprintf(out, "%d ", arr[i]);
        }
        fprintf(out, "\nNumber of comparisons: %d\n", count);
        fprintf(out, "Execution time: %f\n", time);
        fclose(in);
        fclose(out);
        break;
    }
    case 2:
    {
        FILE *in = fopen("inDesc.dat", "r");
        FILE *out = fopen("outQuickDesc.dat", "w");
        int n = 400;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(in, "%d, ", &arr[i]);
        }
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(out, "Sorted array: ");
        for (int i = 0; i < n; i++)
        {
            fprintf(out, "%d ", arr[i]);
        }
        fprintf(out, "\nNumber of comparisons: %d\n", count);
        fprintf(out, "Execution time: %f\n", time);
        fclose(in);
        fclose(out);
        break;
    }
    case 3:
    {
        FILE *in = fopen("inRand.dat", "r");
        FILE *out = fopen("outQuickRand.dat", "w");
        int n = 400;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(in, "%d, ", &arr[i]);
        }
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(out, "Sorted array: ");
        for (int i = 0; i < n; i++)
        {
            fprintf(out, "%d ", arr[i]);
        }
        fprintf(out, "\nNumber of comparisons: %d\n", count);
        fprintf(out, "Execution time: %f\n", time);
        fclose(in);
        fclose(out);
        break;
    }
    case 4:
    {
        printf("Ending...\n");
        break;
    }
    }

    printf("\nHarshil Gupta");
    printf("\n2105889");
    printf("\nCSE 32");
}