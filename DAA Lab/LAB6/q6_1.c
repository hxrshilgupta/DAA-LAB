// Aim of the program: Write a program to find the maximum profit nearest to but not exceeding the given knapsack capacity using the Fractional Knapsack algorithm. Notes# Declare a structure ITEM having data members item_id, item_profit, item_weight and profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order, according to their profit /weight.

#include <stdio.h>

struct item
{
    int id;
    int profit;
    int weight;
    float ratio;
};

void heapify(struct item arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l].ratio > arr[largest].ratio)
    {
        largest = l;
    }
    if (r < n && arr[r].ratio > arr[largest].ratio)
    {
        largest = r;
    }
    if (largest != i)
    {
        struct item temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(struct item arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        struct item temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct item arr[n];
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the item id, profit and weight of each item:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &arr[i].id, &arr[i].profit, &arr[i].weight);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }
    heapSort(arr, n);
    int i = 0;
    float profit = 0;
    i = n - 1;
    while (capacity > 0 && i > 0)
    {
        if (arr[i].weight <= capacity)
        {
            profit += arr[i].profit;
            capacity -= arr[i].weight;
        }
        else
        {
            profit += arr[i].ratio * capacity;
            capacity = 0;
        }
        i--;
    }

    printf("Item No\t Profit\t Weight\t Amount to be taken\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d\t %d\t %d\t %f\n", arr[i].id, arr[i].profit, arr[i].weight, arr[i].ratio);
    }
    printf("Maximum profit: %.2f\n", profit);

    printf("\nHarshil Gupta");
    printf("\n2105889");
    printf("\nCSE 32");
    return 0;
}