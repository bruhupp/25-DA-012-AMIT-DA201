//Name: Amit
//Roll Number: 25/DA/012
//8. Write a program to find the Minimum Spanning Tree of a weighted graph using Prims and Kruskal's algorithm.

//KRUSKAL'S ALGORITHM
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

struct Edge
{
    int source;
    int destination;
    int weight;
};

// Sort edges according to weight
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

// Find the parent of a vertex
int findParent(int parent[], int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;

    return parent[vertex] = findParent(parent, parent[vertex]);
}

// Join two sets
void unionSets(int parent[], int rank[], int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
        parent[u] = v;

    else if (rank[u] > rank[v])
        parent[v] = u;

    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[MAX];

    cout << "Enter source, destination and weight of each edge:\n";

    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].source
            >> edges[i].destination
            >> edges[i].weight;
    }

    // Sort edges by weight
    sort(edges, edges + e, compare);

    int parent[MAX];
    int rank[MAX];

    // Initialize each vertex as its own set
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalWeight = 0;
    int edgesSelected = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    for (int i = 0; i < e && edgesSelected < n - 1; i++)
    {
        int u = edges[i].source;
        int v = edges[i].destination;

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        // If they belong to different sets, no cycle is formed
        if (parentU != parentV)
        {
            cout << u << " - " << v
                 << "\t" << edges[i].weight << endl;

            totalWeight += edges[i].weight;
            edgesSelected++;

            unionSets(parent, rank, parentU, parentV);
        }
    }

    cout << "\nTotal weight of MST = " << totalWeight;

    return 0;
}
