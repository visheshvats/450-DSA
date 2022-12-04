#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> vis(n+1);
        queue<int> q;
        int a,b,c;
        vector<pair<int,int>> adj[n+1];


        for(int i=0;i<roads.size();i++)
        {
            a=roads[i][0];
            b=roads[i][1];
            c=roads[i][2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }

        vis[1]=true;
        q.push(1);
        int ans =INT_MAX;

        while(!q.empty())
        {
            int a = q.front();
            q.pop();

            for(pair<int,int> it : adj[a])
            {
                ans=min(ans,it.second);
                if(!vis[it.first])
                {
                    q.push(it.first);
                    vis[it.first]=true;
                }
            }
        }

        return ans;
        
    }
};