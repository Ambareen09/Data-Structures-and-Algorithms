/*
What is Topological Sorting?
----------------------------
Topological sorting for Directed Acyclic Graph is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.
*/

#include <bits/stdc++.h>
using namespace std;

int graph[10][10];

void createGraph(int i, int j, vector<int> &indegree)
{
    graph[i][j] = 1;

    indegree[j]++;
}

void KhansAlgorithm(int v, vector<int> &indegree)
{
    vector<int> answer;
    queue<int> q;
    for (int i = 1; i <= v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int current = q.front();
        answer.push_back(current);
        q.pop();

        for (int i = 1; i <= v; i++)
        {
            if(graph[current][i] != 0)
            {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
    }

    for (int i = 0; i < v; i++)
        cout << answer[i] << "  ";
}

int main()
{
    int V, edge, i, j;

    cout << "\nEnter the number of vertex : ";
    cin >> V;

    vector<int> indegree(V + 1, 0);

    for (i = 1; i <= V; i++)
        for (j = 1; j <= V; j++)
            graph[i][j] = 0;

    for (i = 1; i <= V; i++)
    {
        while (1)
        {
            cout << "Enter the edges from " << i << " or press -1 : ";
            cin >> edge;
            if (edge == -1)
                break;
            createGraph(i, edge, indegree);
        }
    }

    KhansAlgorithm(V, indegree);

    return 0;
}
