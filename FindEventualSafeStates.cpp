#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int node, vector<bool> &vis, vector<bool> &path,vector<bool> &check, vector<vector<int>> &adj)
    {
        vis[node]=true;
        path[node]=true;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, vis, path,check, adj)==false)
                {
                    check[node]=false;
                    return false;
                }  
            }
            else if(path[it])
            {
                return false;
            }

        }


        check[node]=true;
        path[node]=false;
        return true;;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int v = adj.size();
        

        vector<bool> vis(v,0);
        vector<bool> path(v,0);
        vector<bool> check(v,0);

        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,path,check,adj);
            }
        }

        vector<int> ans;
        for(int i=0;i<v;i++)
        {
            if(!check[i])    ans.push_back(i);
        }

        return ans;
        
    }
};