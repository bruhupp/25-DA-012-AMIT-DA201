//Name: Amit
//Roll Number: 25/DA/012
//10. Write a program to find the Single Source Shortest Path using the Bellman-Ford algorithm and extend it to detect negative-weight cycles in a weighted directed graph. 
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge
{
    int source, destination, weight;    
};

void bellmanFord(int V, int E, vector<Edge>& edges, int source)
{
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i < V; i++)
    {
        bool updated = false;

        for (const Edge& edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            if (distance[u] != INT_MAX &&
                distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                updated = true;
            }
        }

        if (!updated)
            break;
    }

    // Check for a negative-weight cycle
    for (const Edge& edge : edges)
    {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;

        if (distance[u] != INT_MAX &&
            distance[u] + w < distance[v])
        {
            cout << "\nNegative-weight cycle detected!\n";
            return;
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";
    cout << "Vertex\tDistance\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << "\t";

        if (distance[i] == INT_MAX)
            cout << "INF";
        else
            cout << distance[i];

        cout << endl;
    }

    cout << "\nNo negative-weight cycle reachable from source.\n";
}

int main()
{
    int V, E, source;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter source, destination and weight of each edge:\n";

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].source
            >> edges[i].destination
            >> edges[i].weight;
    }

    cout << "Enter source vertex: ";
    cin >> source;

    bellmanFord(V, E, edges, source);

    return 0;
}