#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int solve(int n)
    // {
    //     //bc
    //     if(n==1) return 1;
    //     if(n==2)    return 2;

    //     //rc
    //     return solve(n-1)+solve(n-2);

    // }

    // int solveMEM(int n,vector<int> &dp)
    // {
    //     //bc
    //     if(n==1) return 1;
    //     if(n==2)    return 2;

    //     //rc
    //     if(dp[n]!=-1)   return dp[n];
    //     return dp[n]=solveMEM(n-1,dp)+solveMEM(n-2,dp);

    // }
    // int solveTAB(int n)
    // {
    //     vector<int> dp(n+1,0);
    //     //bc
    //     dp[1]=1;
    //     dp[2]=2;

    //     for(int i=3;i<n+1;i++)
    //     {
    //         dp[i]=dp[i-1]+dp[i-2];
    //     }

    //     return dp[n];

    // }

    int solveSO(int n)
    {
        vector<int> dp(n+1,0);
        //bc
        int a =1;
        int b =2;
        int c;

        for(int i=3;i<n+1;i++)
        {
            c=b+a;
            a=b;
            b=c;
        }

        return c;

    }

    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        if(n==1)    return 1;
        if(n==2)    return 2;
        int ans = solveSO(n);
        return ans;
        
    }
};