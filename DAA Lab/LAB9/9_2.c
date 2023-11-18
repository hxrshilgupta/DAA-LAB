#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGES 100
struct Edge
{
    int src, dest, weight;
};
struct Graph
{
    int V, E;
    struct Edge *edges;
};
struct Subset
{
    int parent;
    int rank;
};
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge *)malloc(E * sizeof(struct Edge));
    return graph;
}
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int compareEdges(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
void kruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E)
    {
        struct Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    // Displaying the selected edges and their costs
    printf("Edge Cost\n");
    for (int i = 0; i < e; i++)
    {
        printf("%d--%d %d\n", result[i].src + 1, result[i].dest + 1,
               result[i].weight);
    }
    // Calculate and display the total weight of the minimum spanning tree
    int totalWeight = 0;
    for (int i = 0; i < e; i++)
    {
        totalWeight += result[i].weight;
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
    free(subsets);
}
int main()
{
    int V, E;
    printf("Enter the Number of Vertices and Edges: ");
    scanf("%d %d", &V, &E);
    struct Graph *graph = createGraph(V, E);
    printf("Enter the Edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph -> edges[i].weight);
    }
    kruskalMST(graph);
    // Freeing allocated memory
    free(graph->edges);
    free(graph);
    return 0;
}
