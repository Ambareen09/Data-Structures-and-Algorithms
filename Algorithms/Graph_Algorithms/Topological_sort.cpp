//Topological sort of a graph

#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
	{
	    vector<int> in(V, 0);
	    vector<int> ans;
	    queue<int> q;
	    for (int i = 0; i < V; i++)
	    {
	        for (auto x : adj[i])
	        {
	            in[x]++;
	        }
	    }
	    for (int i = 0; i < V; i++)
	    {
	        if (in[i] == 0)
	            q.push(i);
	    }

	    while(!q.empty())
	    {
	        int td = q.front();
	        q.pop();
	        ans.push_back(td);
	        for (auto x : adj[td])
	        {
	            in[x]--;
	            if (in[x] == 0)
	            {
	                q.push(x);
	            }
	        }
	    }
	    return ans;
	}

int check(int V, vector <int> &res, vector<int> adj[]) {

    if(V!=res.size())
    return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main()
{
        int n;
        cin >> n;
        while(n--)
        {
        int N, E;
        cin >> N;
        cin >> E;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i];
        }

        cout << check(N, res, adj) << endl;
        }


    return 0;
}
