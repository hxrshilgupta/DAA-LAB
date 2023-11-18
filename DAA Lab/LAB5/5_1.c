#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

// Function to swap two persons
void swap(struct person *x, struct person *y)
{
    struct person temp = *x;
    *x = *y;
    *y = temp;
}

// Function to print the elements of a heap
void printHeap(struct person *arr, int n)
{
    printf("Heap Elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%-4d%-36s%-8d%-11d%-8d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }
}

// Function to create a min-heap based on age
void minHeapifyAge(struct person *arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapifyAge(arr, n, smallest);
    }
}

// Function to create a max-heap based on weight
void maxHeapifyWeight(struct person *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapifyWeight(arr, n, largest);
    }
}

// Function to build a min-heap based on age
void buildMinHeapAge(struct person *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapifyAge(arr, n, i);
}

// Function to build a max-heap based on weight
void buildMaxHeapWeight(struct person *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapifyWeight(arr, n, i);
}

int main()
{
    int option, n = 0;
    struct person *students = NULL;

    while (1)
    {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on age\n");
        printf("3. Create a Max-heap based on weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            FILE *file = fopen("student_data.txt", "r");
            if (file == NULL)
            {
                printf("File not found!\n");
                break;
            }

            struct person newPerson; // Create a temporary person struct

            while (fscanf(file, "%d", &newPerson.id) == 1)
            {
                // Allocate memory for the name field
                newPerson.name = (char *)malloc(256);

                // Read the name, age, height, and weight
                fscanf(file, " %[^\n]s", newPerson.name);
                fscanf(file, "%d %d %d", &newPerson.age, &newPerson.height, &newPerson.weight);

                // Allocate memory for the students array
                students = (struct person *)realloc(students, (n + 1) * sizeof(struct person));

                // Copy the data to the students array
                students[n] = newPerson;

                // Print the data
                printf("%-4d%-36s%-8d%-11d%-8d\n", students[n].id, students[n].name, students[n].age, students[n].height, students[n].weight);

                n++; // Increment the count of students
            }

            fclose(file);
            break;
        }
        case 2:
        {
            if (n == 0)
            {
                printf("No data to create a Min-heap. Read data first (Option 1).\n");
                break;
            }

            buildMinHeapAge(students, n);
            printf("Min-heap based on age created.\n");

            // Print the Min-heap
            printHeap(students, n);
            break;
        }
        case 3:
        {
            if (n == 0)
            {
                printf("No data to create a Max-heap. Read data first (Option 1).\n");
                break;
            }

            buildMaxHeapWeight(students, n);
            printf("Max-heap based on weight created.\n");

            // Print the Max-heap
            printHeap(students, n);
            break;
        }
        case 4:
        {
            if (n == 0)
            {
                printf("No data available. Read data first (Option 1).\n");
                break;
            }

            float youngestWeightKg = students[0].weight / 2.20462;
            printf("Weight of youngest student: %.2f kg\n", youngestWeightKg);
            break;
        }
        case 5:
        {
            struct person newPerson;
            printf("Enter the details of the new person:\n");
            printf("Id: ");
            scanf("%d", &newPerson.id);
            newPerson.name = (char *)malloc(256);
            printf("Name: ");
            scanf(" %[^\n]s", newPerson.name);
            printf("Age: ");
            scanf("%d", &newPerson.age);
            printf("Height: ");
            scanf("%d", &newPerson.height);
            printf("Weight (in pounds): ");
            scanf("%d", &newPerson.weight);

            n++;
            students = (struct person *)realloc(students, n * sizeof(struct person));
            students[n - 1] = newPerson;
            buildMinHeapAge(students, n);
            printf("New person inserted into the Min-heap based on age.\n");
            break;
        }
        case 6:
        {
            // Free dynamically allocated memory and exit
            for (int i = 0; i < n; i++)
            {
                free(students[i].name);
            }
            free(students);
            exit(0);
        }
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
    printf("\nHarshil Gupta");
    printf("\n2105889");
    printf("\nCSE 32");
    return 0;
}