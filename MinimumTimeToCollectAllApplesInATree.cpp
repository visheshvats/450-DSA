#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int node, int parent, vector<int> adj[], vector<bool> &hasApple)
    {
        //bc


        //rc
        int totaltime =0, childtime=0;
        for(auto it : adj[node])
        {
            if(it!=parent)
            {
                childtime+=dfs(it,node, adj, hasApple);
            }
        }
        if(childtime||hasApple[node])   totaltime=childtime+2;

        return totaltime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int a =edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = dfs(0,-1,adj, hasApple);
        return ans;
    }
};