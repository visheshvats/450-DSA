#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int> &dp)
    {
        //bc
        if(n<=0)    return 0;
        if(n==1)    return 1;
        if(n==2)    return 2;

        //rc
        if(dp[n]!=-1)   return dp[n];

        int a = solve(n-1,dp);
        int b= solve(n-2,dp);
        return dp[n]=a+b;
    }
    int solveTAB(int n)
    {
        if(n<=0)    return 0;
        if(n==1)    return 1;
        if(n==2)    return 2;
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int solveSO(int n)
    {
        if(n<=0)    return 0;
        if(n==1)    return 1;
        if(n==2)    return 2;
        int curr;
        int prev2=1;
        int prev1=2;
        for(int i=3;i<=n;i++)
        {
            curr=prev2+prev1;
        }
        return curr;
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // int ans = solve(n,dp);
        // int ans = solveTAB(n);
        int ans = solveSO(n);
        return ans;
        
    }
};