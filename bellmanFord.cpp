#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

void bellmanFord(vector<Edge> &edges, int V, int E, int src)
{
    vector<int> distance(V, INT_MAX);
    distance[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
            }
        }
    }
    for (int j = 0; j < E; j++)
    {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
        {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }
    cout << "Vertex Distance from Source:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t" << distance[i] << endl;
    }
}

int main()
{
    int V, E, src;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Enter each edge's source, destination, and weight:" << endl;
    for (int i = 0; i < E; i++)
    {
        cout << "Edge " << i + 1 << " - Source: ";
        cin >> edges[i].src;
        cout << "Edge " << i + 1 << " - Destination: ";
        cin >> edges[i].dest;
        cout << "Edge " << i + 1 << " - Weight: ";
        cin >> edges[i].weight;
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    bellmanFord(edges, V, E, src);

    return 0;
}
