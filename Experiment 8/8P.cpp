//Name: Amit
//Roll Number: 25/DA/012
//8. Write a program to find the Minimum Spanning Tree of a weighted graph using Prims and Kruskal's algorithm.

//PRIMS ALGORITHM
#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int main()
{
    int n;
    int graph[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the weighted adjacency matrix:\n";
    cout << "(Enter 0 if there is no edge)\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int parent[MAX];
    int key[MAX];
    bool visited[MAX];

    // Initialize
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    // Start from vertex 0
    key[0] = 0;

    // Find MST
    for (int count = 0; count < n - 1; count++)
    {
        int minKey = INT_MAX;
        int u = -1;

        // Find the minimum key vertex
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }

        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Display MST
    int totalWeight = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    cout << "Edge\tWeight\n";

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        totalWeight += graph[i][parent[i]];
    }

    cout << "\nTotal weight of MST = " << totalWeight;

    return 0;
}
