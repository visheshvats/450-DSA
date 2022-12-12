#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> adj[graph.size()];

        for(int i=0;i<graph.size();i++)
        {
            for(auto x:graph[i])
            {
                adj[x].push_back(i);
            }
        }

        vector<int> topo;
        vector<bool> vis(graph.size(),0);
        queue<int> q;
        unordered_map<int, int> indegree;

        for(int i=0;i<graph.size();i++)
        {
            for(auto it : adj[i])
                indegree[it]++;
        }

        for (int i = 0; i < graph.size(); i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            topo.push_back(n);

            for(auto it : adj[n])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }

        sort(begin(topo), end(topo));

        return topo;
        

        
    }
};