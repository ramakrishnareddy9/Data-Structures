#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4

int primsAlgorithm(int graph[N][N], int n)
{
    int mstCost = 0;
    bool visited[N] = {false};
    int edgeWeights[N];

    for (int i = 0; i < n; i++)
        edgeWeights[i] = INT_MAX;

    edgeWeights[0] = 0;

    for (int count = 0; count < n; count++)
    {
        int minWeight = INT_MAX, currentNode = -1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && edgeWeights[i] < minWeight)
            {
                minWeight = edgeWeights[i];
                currentNode = i;
            }
        }

        mstCost += minWeight;
        visited[currentNode] = true;

        for (int i = 0; i < n; i++)
        {
            if (graph[currentNode][i] && !visited[i] && graph[currentNode][i] < edgeWeights[i])
            {
                edgeWeights[i] = graph[currentNode][i];
            }
        }
    }
    return mstCost;
}

int newMSTCost(int originalCost, int numEdges)
{
    return originalCost + numEdges;
}

int main()
{
    int graph[N][N] = {
        {0, 2, 0, 6},
        {2, 0, 3, 8},
        {0, 3, 0, 7},
        {6, 8, 7, 0}};

    int originalCost = primsAlgorithm(graph, N);
    int updatedCost = newMSTCost(originalCost, N - 1);

    printf("Original MST Cost: %d\n", originalCost);
    printf("Updated MST Cost: %d\n", updatedCost);

    return 0;
}
