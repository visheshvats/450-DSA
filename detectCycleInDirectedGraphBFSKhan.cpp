#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<bool> &vis, vector<bool> &path, vector<int> adj[])
{
    vis[i]=true;
    path[i]=true;

    for(auto it : adj[i])
    {
        if(!vis[it])
        {
            if(dfs(it,vis,path,adj))    return true;
        }
        else if(path[it])   return true;
    }





    path[i]=false;
    return false;

}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
    vector<bool> vis(v,0);
    vector<bool> path(v,0);

    vector<int> adj[v];

    for(int i=0;i<e;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,vis,path,adj)) return true;
        }
    }

    return false;

}
