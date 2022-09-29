#include<bits/stdc++.h>
using namespace std;


vector<int> BFS(vector<int> adj[], int N, int src) 
{
    vector<int> dis(N,INT_MAX);

    queue<int> q;
    dis[src]=0;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adj[node])
        {
            
            if(dis[node]+1<dis[it])
            {
                dis[it]=dis[node]+1;
                q.push(it);
            }
        }
    }
	
	
}