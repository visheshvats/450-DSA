#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> adj[], vector<int> &parent, int par)
{
    parent[1]=1;

    for(auto it: adj[i])
    {
        if(it!=par)
            dfs(it, adj, parent, i);
    }

}


vector<int> nodeSearching(vector<vector<int>>&edges, vector<int>&v, vector<vector<int>>&queries) {
	// Write your code here.
    int n = v.size();
    vector<int> adj[n+1];

    for(int i=0;i<edges.size();i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }

    vector<int> parent(n+1,0);
    parent[1]=1;

    dfs(1,adj, parent, 1);

    vector<int> ans(queries.size());

    for(int i=0;i<queries.size();i++)
    {
        int node = queries[i][0];
        int val = queries[i][1];

        if(val>v[0])
        {
            ans.push_back(-1);
            continue;
        }
        
    }



    
}
