/*
What is DFS?
------------
Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node 
and explores as far as possible along each branch before backtracking.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int v;
    list<int> *graph;

public:
    Graph(int v)
    {
        this->v = v;
        graph = new list<int>[v];
    }

    void addEdges(int e1, int e2)
    {
        graph[e1].push_back(e2);
        graph[e2].push_back(e1);
    }

    void display(int v)
    {
        cout << "List representation of the graph is : " << endl;
        for (int i = 0; i < v; i++)
        {
            cout << i << " --> ";

            for (auto v : graph[i])
                cout << i << "  ";
            cout << endl;
        }
    }

    void DFS(int source, vector<int> &visited)
    {
        visited[source] = 1;
        cout << source << "  ";

        for (auto i : graph[source])
            if (!visited[i])
                DFS(i, visited);
    }
};

int main()
{
    int v = 4;
    Graph g(v);

    g.addEdges(0, 1);
    g.addEdges(0, 2);
    g.addEdges(1, 2);
    g.addEdges(2, 3);

    g.display(v);

    int source = 0;
    vector<int> visited(v, 0);
    cout << "BFS of the graph is : ";
    g.DFS(source, visited);

    return 0;
}
