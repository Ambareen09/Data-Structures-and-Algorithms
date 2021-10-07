/*
What is Hamiltonian Path?
-------------------------
In an undirected graph, the Hamiltonian path is a path, that visits each vertex exactly once, and the Hamiltonian cycle or circuit is a Hamiltonian path, 
that there is an edge from the last vertex to the first vertex. 

Problem Statement:
-----------------
Determine whether the graph contains a Hamiltonian cycle or not.
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

    bool Hamiltonian_Path(int source, vector<int> &path, vector<int> &visited)
    {
        if (path.size() == V)
            return true;

        for (auto i : graph[source])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                path.push_back(i);

                if (Hamiltonian_Path(i, path, visited))
                    return true;

                // BACKTRACKING:
                visited[i] = 0;
                path.pop_back();
            }
        }
        return false;
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

    // Checking all the hamiltonian paths and cycles :
    for (int i = 0; i < V; i++)
    {
        vector<int> path;
        vector<int> visited(V, 0);
        path.push_back(i);
        visited[i] = 1;
        
        if (g.Hamiltonian_Path(i, path, visited))
        {
            cout << "Hamiltonian Path : ";
            for (int j = 0; j < path.size(); j++)
                cout << path[j] << "  ";

            // Checking for the Hamiltonian Cycle:
            bool find = false;
            for (auto it = g.graph[i].begin(); it != g.graph[i].end(); it++)
                if (*it == path[V - 1])
                    find = true;

            if (find)
                cout << "\nHamiltonian Cycle is present! " << endl;
            else
                cout << "\nHamiltonian Cycle is not present! " << endl;
        }
    }

    return 0;
}
