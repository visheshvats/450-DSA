#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
    vector<int> adj[n+1];

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    unordered_map<int, bool> vis;
    unordered_map<int, int> parent;

    q.push(s);
    vis[s]=true;
    parent[s]=-1;

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        for(auto it:adj[n])
        {
            if(!vis[it])
            {
                vis[it]=true;
                parent[it]=n;
                q.push(it);
            }
        }
    }

    vector<int> ans;
    ans.push_back(t);
    int curr = t;

    while(curr!=s)
    {
        curr = parent[curr];
        ans.push_back(curr);
    }

    reverse(ans.begin(), ans.end());

    return ans;

    


	
}
