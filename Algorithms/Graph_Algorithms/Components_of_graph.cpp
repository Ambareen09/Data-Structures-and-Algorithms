/*
Problem Statement:
-----------------
Given an undirected graph, print all connected components line by line.
*/


#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *graph;

public:
    Graph(int V)
    {
        this->V = V;
        graph = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    void connectedComponents(int source, vector<int> &visited)
    {
        if(!visited[source])
        {
            cout<<source<<"  ";
            visited[source] = 1;
            
            for(auto i: graph[source])
                if(!visited[i])
                    Graph::connectedComponents(i, visited);
        }
    }
};

int main()
{
    int v = 5;
    Graph g(v);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    int counter = 0;
    vector<int> visited(v, 0);

    cout << "Following are connected components :  \n";
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            g.connectedComponents(i, visited);
            cout<<endl;
            counter++;
        }
    }

    cout << "\nTotal connected components are : " << counter;

    return 0;
}
