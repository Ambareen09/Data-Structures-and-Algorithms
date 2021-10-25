//Detect cycle in a directed graph



#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}

bool solve(int src, vector<int> &vis, vector<int> &order, vector<int> adj[])
	{
	    vis[src] = 1;
	    order[src] = 1;
	    for (auto x: adj[src])
	    {
	        if(!vis[x])
	        {
	            bool confirm = solve(x, vis, order, adj);
	            if (confirm == true)
	                return true;
	        }
	        else if (order[x])
	            return true;
	    }
	    order[src] = 0;
	    return false;
	}

bool isCyclic(int V, vector<int> adj[])
	{
	   	vector<int> vis(V, 0);
	   	vector<int> order(V, 0);
	   	for (int i = 0; i < V; i++)
	   	{
	   	    if(!vis[i])
	   	    {
	   	        if(solve(i, vis, order, adj))
	   	            return true;
	   	    }
	   	}
	   	return false;
	}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int V, E;
    cin >> V;
    cin >> E;
    int a, b;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        cin >> a;
        cin >> b;
        addEdge(adj, a, b);
    }
    cout << isCyclic(V, adj);
    }
    return 0;
}



