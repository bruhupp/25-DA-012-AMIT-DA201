//Name: Amit
//Roll Number: 25/DA/012
//9. Write a program to find the Single Source Shortest Path using Dijikstra's Algorithm.
#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

void dijkstra(int graph[MAX][MAX], int n, int source)
{
    int distance[MAX];
    bool visited[MAX];

    // Initialize distances and visited array
    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance of source from itself is 0
    distance[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++)
    {
        int minDistance = INT_MAX;
        int u = -1;

        // Find the unvisited vertex with minimum distance
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && distance[i] < minDistance)
            {
                minDistance = distance[i];
                u = i;
            }
        }

        // Mark the selected vertex as visited
        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    // Display shortest distances
    cout << "\nShortest distances from source vertex "
         << source << ":\n";

    cout << "Vertex\tDistance\n";

    for (int i = 0; i < n; i++)
    {
        if (distance[i] == INT_MAX)
            cout << i << "\t" << "INF" << endl;
        else
            cout << i << "\t" << distance[i] << endl;
    }
}

int main()
{
    int graph[MAX][MAX];
    int n, source;

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

    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(graph, n, source);

    return 0;
}