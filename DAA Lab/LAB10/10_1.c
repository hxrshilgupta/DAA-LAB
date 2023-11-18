#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100
// Function to find the vertex with the minimum distance value
int path[MAX_VERTICES];
int minDistance(int distance[], int sptSet[], int vertices)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++)
    {
        if (sptSet[v] == 0 && distance[v] <= min)
        {
            min = distance[v];
            min_index = v;
        }
    }
    return min_index;
}
// Function to print the solution
void printSolution(int distance[], int vertices, int source)
{
    printf("\tSource\tDestination \tCost \tPath\n");
    for (int i = 0; i < vertices; i++)
    {
        if (i != source)
        {
            printf("\t%d \t%d \t%d \t%d", source + 1, i + 1, distance[i], source + 1);
            // Print the path
            int current = i;
            while (current != source)
            {
                printf("-->%d", current + 1);
                current = path[current];
            }
            printf("\n");
        }
    }
}
// Dijkstra's algorithm to find the shortest paths
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int source)
{
    int distance[MAX_VERTICES];                                         // The output array distance[i] holds the shortest distance from source to vertex i
    int sptSet[MAX_VERTICES]; // sptSet[i] will be true if vertex i is included in the shortest path tree or the shortest distance from source to vertex i is finalized
    int path[MAX_VERTICES]; // To store the shortest path
    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
        sptSet[i] = 0;
    }
    // Distance from source to itself is always 0
    distance[source] = 0;
    // Find shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet         processed
        int u = minDistance(distance, sptSet, vertices);
        // Mark the picked vertex as processedsptSet[u] = 1;
        // Update distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++)
        {
            // Update distance[v] only if it is not in the shortest path tree,there is an edge from u to v, and the total weight of path from source to v through u is less than the current value of distance[v]
            if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
                path[v] = u;
            }
        }
    }
    // Print the constructed distance array
    printSolution(distance, vertices, source);
}
int main()
{
    int vertices, source;
    int graph[MAX_VERTICES][MAX_VERTICES];
    // Read graph from the input file
    FILE *file = fopen("inDiAdjMat1.dat", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    // Input the number of vertices
    printf("Enter the Number of Vertices: ");
    scanf("%d", &vertices);
    // Input the source vertex
    printf("Enter the Source Vertex: ");
    scanf("%d", &source);
    // Input the adjacency matrix
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);
    // Run Dijkstra's algorithm
    dijkstra(graph, vertices, source - 1);

    printf("\nHarshil Gupta");
    printf("\n2105889");
    printf("\nCSE 32\n");

    return 0;
}