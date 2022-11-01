#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int solve(int n, int m)
{
    
    //bc
    if(n<m)
        return 0;
    if(n==0||m==0)
        return 0;
    if(n==m)
        return 1;

    //rc
    int ans = (solve(n-1, m-1)+solve(n,m*2));

    return ans;
}

int solveMem(int n, int m, vector<vector<int>> &dp)
{
    int mod = 1e9 + 7;
    //bc
    if(n<m)
        return 0;
    if(n==0||m==0)
        return 0;
    if(n==m)
        return 1;

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //         if(i==j)
    //             dp[i][j]=1;
    // }

    if(dp[n][m]!=-1)
        return dp[n][m];

    //rc
    

    return dp[n][m] = (solveMem(n-1, m-1,dp)+solveMem(n,m*2,dp))%mod;
}

int noOfArrays(int n, int m) {
    
    // Write your code here.
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

    int ans = solveMem(n,m, dp);

    return ans;
}