#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dis(n,1e9);
        vector<pair<int,int>> adj[n];

        int edgenumber = flights.size();

        for(int i=0;i<edgenumber;i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        queue<pair<int, pair<int, int>>> q;
        dis[src]=0;

        q.push({0,{src,0}});

        while(!q.empty())
        {
            auto it = q.front();
            int step = it.first;
            int node = it.second.first;
            int distance = it.second.second;
            q.pop();
            if(node==dst)   continue;
            if(step<=k)
            {
                for(auto nextit:adj[node])
                {
                    int nextnode = nextit.first;
                    int distreq = nextit.second;
                    if(distance+distreq<dis[nextnode])
                    {
                        dis[nextnode]=distance+distreq;
                        q.push({step+1,{nextnode, dis[nextnode]}});
                    }
                }
            }



        }


        if(dis[dst]==1e9)   return -1;
        return dis[dst];
        
    }
};
