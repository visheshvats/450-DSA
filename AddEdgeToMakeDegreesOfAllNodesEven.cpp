#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n+1);
        vector<int> odd;
        for(auto it : edges)
        {
            int a = it[0];
            int b = it[1];
            adj[a].insert(b);
            adj[b].insert(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size()%2==1)
                odd.push_back(i);
        }
        if(odd.size()==2)
        {
            for(int i=1;i<=n;i++)
            {
                if(adj[odd[0]].count(i)==0&&adj[odd[1]].count(i)==0)
                    return true;
            }
        }
        if(odd.size()==4)
        {
            return (adj[odd[0]].count(odd[1])==0&&adj[odd[2]].count(odd[3])==0)
                    ||(adj[odd[0]].count(odd[2])==0&&adj[odd[1]].count(odd[3])==0)
                    ||(adj[odd[0]].count(odd[3])==0&&adj[odd[2]].count(odd[1])==0);
        }

        return odd.size()==0;

        
    }
};