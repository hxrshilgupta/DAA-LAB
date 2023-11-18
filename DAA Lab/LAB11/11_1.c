//FLOYD's WARSHALL ALGO
#include <stdio.h>
#define INFINITY 9999
int main()
{
    int n, source, destination;
    // Read the number of vertices from the input
    printf("Number of Vertices: ");
    scanf("%d", &n);
    // Create an adjacency matrix to store the graph
    int adjMatrix[n][n];
    // Read the adjacency matrix from the input file
    FILE *inputFile = fopen("inDiAdjMat2.dat", "r");
    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(inputFile, "%d", &adjMatrix[i][j]);
            if (adjMatrix[i][j] == 0)
            {
                adjMatrix[i][j] = INFINITY;
            }
        }
    }
    fclose(inputFile);
    // Apply Floyd-Warshall's algorithm to find the shortest paths
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adjMatrix[i][k] != INFINITY && adjMatrix[k][j] != INFINITY)
                {
                    adjMatrix[i][j] = adjMatrix[i][j] > (adjMatrix[i][k] + adjMatrix[k][j]) ? (adjMatrix[i][k] + adjMatrix[k][j]) : adjMatrix[i][j];
                }
            }
        }
    }
    // Read the source and destination vertices from the input
    printf("Enter the source and destination vertex: ");
    scanf("%d %d", &source, &destination);
    // Print the shortest path weight matrix
    printf("\nShortest Path Weight Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", adjMatrix[i][j]);
        }
        printf("\n");
    }
    // Find the intermediate vertices on the shortest path from source to destination
    int path[n];
    for (int i = 0; i < n; i++)
    {
        path[i] = -1;
    }
    int current = destination;
    while (current != source)
    {
        for (int k = 0; k < n; k++)
        {
            if (adjMatrix[source][current] == adjMatrix[source][k] + adjMatrix[k][current])
            {
                path[current] = k;
                current = k;
                break;
            }
        }
    }
    // Print the path from source to destination
    printf("\nHarshil Gupta");
    printf("\n2105889");
    printf("\nCSE 32");
    printf("\nShortest Path from vertex %d to vertex %d: ", source, destination);
    int i = source;
    while (i != destination)
    {
        printf("%d--&gt;", i);
        i = path[i];
    }
    printf("%d\n", destination);
    // Print the path weight
    printf("Path weight: %d\n", adjMatrix[source][destination]);
    return 0;
}