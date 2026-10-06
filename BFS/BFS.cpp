//Name: Amit
//Roll Number: 25/DA/012
// Write a program to perform BFS Traversal.
#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

void BFS(int graph[MAX][MAX], int n, int start)
{
    bool visited[MAX] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout << vertex << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int graph[MAX][MAX];
    int n, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(graph, n, start);

    return 0;
}