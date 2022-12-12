#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long ans=0;
    int s;

    int dfs(int i, int prev, vector<int> adj[])
    {
        int people =1;

        for(auto it: adj[i])
        {
            if(it!=prev)
                people+=dfs(it,i, adj);
        }
        if(i!=0)
            ans +=(people+s-1)/s;

        return people;

    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<int> adj[roads.size()+1];
        s=seats;
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        dfs(0,-1,adj);

        return ans;

        
    }
};