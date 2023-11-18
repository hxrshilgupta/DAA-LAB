#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define INF -1

int adj[MAX_NODES][MAX_NODES];
int queue[MAX_NODES];
int visited[MAX_NODES];
int distance[MAX_NODES];

int front = -1, rear = -1;

void enqueue(int node)
{
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = node;
}

int dequeue()
{
    int node = queue[front++];
    if (front > rear)
    {
        front = rear = -1;
    }
    return node;
}

void bfs(int start, int n)
{
    enqueue(start);
    visited[start] = 1;
    distance[start] = 0;

    while (front != -1)
    {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 1; i <= n; i++)
        {
            if (adj[node][i] && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
                distance[i] = distance[node] + 2;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        distance[i] = INF;
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    int start;
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start, n);

    printf("\nDistance [");
    for (int i = 1; i <= n; i++)
    {
        printf("%d", distance[i]);
        if (i < n)
        {
            printf(" ");
        }
    }
    printf("]\n");

    printf("\nHarshil Gupta");
    printf("\n2105889");
    printf("\nCSE 32");
    return 0;
}