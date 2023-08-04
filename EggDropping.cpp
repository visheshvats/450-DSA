#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int f(int n, int e,vector<vector<int>> &dp)
    {
        //bc
        if(n==1)    return 1;
        if(n==0)    return 0;
        if(e==1)    return n;

        //rc
        if(dp[n][e]!=-1)    return dp[n][e];
        int mini=INT_MAX;
        for(int i=1;i<n;i++)
        {
            int low, high;
            if(dp[n-i][e-1]!=-1)
            {
                low=dp[n-i][e-1];
            }
            else
            {
                low=f(n-i,e-1);
            }
            if(dp[i-1][e]!=-1)
            {
                high=dp[i-1][e];
            }
            else
            {
                high=f(i-1,e);
            }
            int temp = max(low, high)+1;
            mini=min(mini,temp);
        }

        return dp[n][e]=mini;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        int ans = f(n,k,dp);
        return ans;

        
    }
};