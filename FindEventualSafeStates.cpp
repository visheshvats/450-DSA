#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int i, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &pathvis, vector<int> &check)
    {
        vis[i]=true;
        pathvis[i]=true;

        for (auto it:graph[i])
        {
            if(!vis[it])
            {
                if(dfs(it, graph, vis, pathvis, check)==true)
                    {
                        check[i]=0;
                        return true;
                    }
            }

            else if(pathvis[it])
                {
                    check[i]=0;
                    return true;
                }
        }

        pathvis[i]=false;
        check[i]=true;

        return false;
        

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();

        vector<bool> pathvis(n,0);
        vector<int> ans;
        vector<int> check(n, 0);
        

        vector<bool> vis(n,0);
        for (int i = 0; i < graph.size(); i++)
        {
            /* code */
            if(!vis[i])
            {
                dfs(i,graph, vis, pathvis,check);
            }


        }

        for (int i = 0; i < n; i++)
        {
            /* code */
            if(check[i]==1)
                ans.push_back(i);
        }

        return ans;
        
        
        
    }
};