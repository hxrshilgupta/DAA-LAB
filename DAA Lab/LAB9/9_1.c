#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

// Function to find the minimum key value in the set of vertices not yet included in the minimum spanning tree
int minKey(int key[], int mstSet[], int n)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to display the cost adjacency matrix of the minimum spanning tree
void displayMST(int parent[], int n, int graph[MAX_VERTICES][MAX_VERTICES])
{
    printf("Cost Adjacency Matrix of Minimum Spanning Tree:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("0\t");
            }
            else
            {
                printf("%d\t", graph[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to apply Prim's algorithm to find the minimum spanning tree
void primMST(int n, int graph[MAX_VERTICES][MAX_VERTICES], int startVertex)
{
    int parent[MAX_VERTICES]; // Array to store the constructed MST
    int key[MAX_VERTICES];    // Key values used to pick minimum weight edge in cut
    int mstSet[MAX_VERTICES]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include the starting vertex first
    key[startVertex - 1] = 0;
    parent[startVertex - 1] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < n - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in the MST
        int u = minKey(key, mstSet, n);

        // Add the picked vertex to the MST set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    // Display the cost adjacency matrix of the minimum spanning tree
    displayMST(parent, n, graph);
    // Calculate and display the total weight of the minimum spanning tree
    int totalWeight = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] != -1)
        {
            totalWeight += graph[i][parent[i]];
        }
    }
    printf("\nTotal Weight of the Spanning Tree: %d\n", totalWeight);
}
int main()
{
    int n, startVertex;
    int graph[MAX_VERTICES][MAX_VERTICES];

    // Read the number of vertices and starting vertex from the user
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter the Starting Vertex: ");
    scanf("%d", &startVertex);

    // Read the cost adjacency matrix from the input file
    FILE *file = fopen("inUnAdjMat.dat", "r");
    if (!file)
    {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);

    // Apply Prim's algorithm and display the results
    primMST(n, graph, startVertex);
    printf("\nHarshil Gupta");
    printf("\n2105889");
    printf("\nCSE 32");
    return 0;
}
