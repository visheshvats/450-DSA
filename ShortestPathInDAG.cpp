#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<pair<int,int>> adj[],vector<bool> &vis, stack<int> &st)
{
	vis[i]=true;

	for(auto it: adj[i])
	{
		if(!vis[it.first])
		{
			dfs(it.first,adj, vis, st);
		}
	}

	st.push(i);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
	vector<pair<int,int>> adj[n];
	for(int i=0;i<m;i++)
	{
		adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
	}

	stack<int> st;
	vector<bool> vis(n,0);

	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i,adj,vis,st);
		}
	}

	vector<int> topo;

	while(!st.empty())
	{
		auto it = st.top();
		st.pop();
		topo.push_back(it);

	}

	vector<int> dis(n,1e9);

	dis[0]=0;

	
	for(auto it:topo)
	{
		for(auto itt:adj[it])
		{
			if(dis[it]+itt.second<dis[itt.first])
			{
				dis[itt.first]=dis[it]+itt.second;
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		if(dis[i]==1e9)
		dis[i]=-1;
	}

	return dis;


}
