#include <bits/stdc++.h> 
using namespace std;

void dfs(int i, vector<int> adj[], vector<bool> &vis)
{
    vis[i]=true;
    for(auto it: adj[i])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis);
        }
    }
}

int findNumOfStates(vector<vector<int>>& roads, int n) {
    // Write your code here.
    vector<int> adj[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(roads[i][j]==1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> vis(n,0);
    int count =0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            count++;
            dfs(i,adj,vis);
        }
    }

    return count;
}