#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<int> maxSum(n,0);

        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);

        }


        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(auto it :adj[i])
            {
                
                if(vals[it]>0)
                    temp.push_back(vals[it]);
                
            }
            sort(begin(temp), end(temp), greater<int>());
            int lej = min(k, (int)temp.size());
            int sum =0;
            for(int j=0;j<lej;j++)
            {
                sum+=temp[j];
            }

            maxSum[i]=sum;
        }

        for(int i=0;i<n;i++)
        {
            maxSum[i]=maxSum[i]+vals[i];
        }

        int le=INT_MIN;

        for(int i=0;i<n;i++)
        {
            le=max(le,maxSum[i]);
        }

        return le;

        
    }
};