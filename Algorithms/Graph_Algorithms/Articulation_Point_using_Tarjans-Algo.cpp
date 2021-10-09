#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *graph;

public:
    Graph(int V)
    {
        this->V = V;
        graph = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void Articulation_Point(int source, vector<int> &discovery, vector<int> &low, vector<int> &ap, vector<int> &parent)
    {
        int counter = 0; // to check if the source vertex is AP or not
        static int time = 0;
        discovery[source] = low[source] = time++;

        for (auto v : graph[source])
        {
            if (discovery[v] != -1)
                low[source] = min(low[source], discovery[v]);
            else
            {
                parent[v] = source;
                counter++;
                Articulation_Point(v, discovery, low, ap, parent);

                low[source] = min(low[source], low[v]);

                // checking the CRITICAL POINT during backtracking.
                if (parent[source] != -1 && low[v] >= discovery[source])
                    ap[source] = 1;
            }
        }
        // Only condition needed to check for the source element.
        if (parent[source] == -1 && counter > 1)
            ap[source] = 1;
    }
};

int main()
{
    int V = 7;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    vector<int> discovery(V, -1);
    vector<int> low(V, -1);
    vector<int> ap(V, -1);
    vector<int> parent(V, -1);

    g.Articulation_Point(0, discovery, low, ap, parent);

    cout << "Ariculation Points : ";
    for (int i = 0; i < V; i++)
        if (ap[i] == 1)
            cout << i << "  ";

    return 0;
}
