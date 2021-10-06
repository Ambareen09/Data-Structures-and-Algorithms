/*
What is Prim's Algorithm?
-------------------------
Prim's algorithm (also known as Jarník's Algorithm) is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. 
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 9999999
#define V 5

int graph[V][V] = {{0, 2, 0, 6, 0},
                   {2, 0, 3, 8, 5},
                   {0, 3, 0, 0, 7},
                   {6, 8, 0, 0, 9},
                   {0, 5, 7, 9, 0}};

int minimumVertex(vector<int> &distance, vector<int> &visited)
{
    int minEdge = INF;
    int result = -1;
    for (int i = 0; i < V; i++)
    {
        if (distance[i] < minEdge and visited[i] == 0)
        {
            minEdge = distance[i];
            result = i;
        }
    }

    return result;
}

void PrimsAlgorithm(vector<int> &distance, vector<int> &parent, vector<int> &visited, int source)
{
    distance[source] = 0;

    for (int i = 0; i < V; i++)
    {
        int minVertex = minimumVertex(distance, visited);
        visited[minVertex] = 1;

        for (int j = 0; j < V; j++)
        {
            if ((graph[minVertex][j] < distance[j]) and (!visited[j]) and (graph[minVertex][j] != 0))
            {
                distance[j] = graph[minVertex][j];
                parent[j] = minVertex;
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << "Parent of " << i << " is : " << parent[i] << " and Distance : " << distance[i] << endl;
}

int main()
{
    vector<int> distance(V, INF);
    vector<int> parent(V, -1);
    vector<int> visited(V, 0);

    PrimsAlgorithm(distance, parent, visited, 0);

    return 0;
}
