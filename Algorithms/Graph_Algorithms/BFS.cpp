/*
What is BFS?
-----------
Breadth first search is a graph traversal algorithm that starts traversing the graph from root node and explores all the neighbouring nodes. 
Then, it selects the nearest node and explore all the unexplored nodes. The algorithm follows the same process for each of the nearest node until it finds the goal.
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

    void BFS(int source)
    {
        vector<int> visited(v, 0);
        queue<int> q;

        cout << source << "  ";
        q.push(source);

        visited[source] = 1;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto v : graph[front])
            {
                if (!visited[v])
                {
                    cout << v << "  ";
                    visited[v] = 1;
                    q.push(v);
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
    g.BFS(source);

    return 0;
}
