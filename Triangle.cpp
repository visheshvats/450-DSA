#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &t, int n)
    {
        //bc
        if(i==n-1) return t[i][j];
        //rc
        int d =t[i][j]+solve(i+1,j,t,n);
        int dia = t[i][j]+solve(i+1,j+1,t,n);
        return min(d, dia);
    }
    int solveMEM(int i, int j, vector<vector<int>> &t, int n, vector<vector<int>> &dp)
    {  
        //bc
        if(i==n-1) return t[i][j];
        //rc
        if(dp[i][j]!=-1) return dp[i][j];
        int d =t[i][j]+solveMEM(i+1,j,t,n,dp);
        int dia = t[i][j]+solveMEM(i+1,j+1,t,n,dp);
        return dp[i][j]=min(d, dia);

    }
    int solveTAB(vector<vector<int>> &t)
    {
        int n=t.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==n-1) dp[i][j]=t[i][j];
                else
                {
                    int curr = t[i][j];
                    dp[i][j]=min(curr+dp[i+1][j],curr+dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int solveSO(vector<vector<int>> &t)
    {
        int n=t.size();
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int> temp(n,0);
            for(int j=i;j>=0;j--)
            {
                if(i==n-1) temp[j]=t[i][j];
                else
                {
                    int curr = t[i][j];
                    temp[j]=min(curr+dp[j],curr+dp[j+1]);
                }
            }
            dp=temp;
        }
        return dp[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        // int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n,-1));
        // int ans = solve(0,0, triangle,n);
        // int ans = solveMEM(0,0, triangle,n,dp);
        // int ans = solveTAB(triangle);
        int ans = solveSO(triangle);

        return ans;
        
    }
};
