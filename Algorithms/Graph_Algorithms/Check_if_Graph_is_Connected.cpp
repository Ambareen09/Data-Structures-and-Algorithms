/*
Problem Statement:
-----------------
Given an un-directed graph. The task is to check if the given graph is connected or not.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    vector<int> *graph;

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

    void dfs(int source, vector<bool> &visited)
    {
        visited[source] = true;

        for (auto v : graph[source])
        {
            if (!visited[v])
                dfs(v, visited);
        }
    }

    void checkifConnected(int source)
    {
        int counter = 0;
        vector<bool> visited(V, false);

        dfs(source, visited);

        for (int i = 0; i < V; i++)
            if (visited[i])
                counter++;

        // If visited count is same as the number of vertices then it is a connected graph.
        if (counter == V)
            cout << "The Graph is connected!";
        else
            cout << "The Graph is dis-connected!";
    }
};

int main()
{
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    int source = 0;
    g.checkifConnected(source);

    return 0;
}
