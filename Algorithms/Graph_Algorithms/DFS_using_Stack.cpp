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
                cout << v << "  ";
            cout << endl;
        }
    }

    void DFS(int source)
    {
        stack<int> s;
        vector<int> visited(v, 0);

        s.push(source);
        visited[source] = 1;
        cout << source << "  ";

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            for (auto v : graph[top])
            {
                if (!visited[v])
                {
                    cout << v << "  ";
                    visited[v] = 1;
                    s.push(v);
                }
            }
        }
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

    cout << "BFS of the graph is : ";
    g.DFS(source);

    return 0;
}
