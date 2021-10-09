/*
Problem Statement:
-----------------
Write a function that checks if a given undirected graph is tree or not.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], int parent);

public:

    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    int visited[10] = {0};

    bool isCyclic(int v , int visited[] , int parent)
    {
        visited[v] = true;

        list<int>::iterator i;
        for(i=adj[v].begin() ; i!=adj[v].end() ; ++i)
        {
            if(!visited[*i])
            {
                if(isCyclic(*i, visited, v))
                    return true;
            }
            else if(*i != parent)
                return true;
        }
        return false;
    }

    bool isTree()
    {
        if(isCyclic(0 , visited , -1))
            return false;

        for(int u=0 ; u<V ; u++)
            if(!visited[u])
                return false;

        return true;
    }

};

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);

    g1.isTree() ? cout<<"Graph is Tree." : cout<<"Graph is not Tree.";

    return 0;
}
