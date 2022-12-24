#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n)
    {
        //bc
        if(m==0&&n==0)
            return 1;
        if(m<0||n<0)
            return 0;
        //rc
        int left = solve(m-1,n);
        int right = solve(m,n-1);
        return left+right;


    }
    int solveMEM(int m , int n, vector<vector<int>> &dp)
    {
        //bc
        if(m==0&&n==0)
            return 1;
        if(m<0||n<0)
            return 0;
        //rc
        if(dp[m][n]!=-1)
            return dp[m][n];
        int left = solve(m-1,n);
        int right = solve(m,n-1);
        return dp[m][n]=left+right;
    }
    int solveTAB(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                    dp[i][j]=1;
                else
                {

                    int left=0;
                    int right =0;
                    if(i>0)
                        left = dp[i-1][j];
                    if(j>0)
                        right = dp[i][j-1];
                    dp[i][j]=left+right;
                }
                
            }
        }

        return dp[m-1][n-1];
    }
    int solveSO(int m , int n)
    {
        vector<int> dp(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                    temp[j]=1;
                else
                {

                    int left=0;
                    int right =0;
                    if(i>0)
                        left = dp[j];
                    if(j>0)
                        right = temp[j-1];
                    temp[j]=left+right;
                }
                
            }
            dp=temp;
        }

        return dp[n-1];
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // int ans= solveMEM(m-1, n-1,dp);
        // int ans = solveTAB(m,n);
        int ans = solveSO(m, n);

        
        // int ans  = solve(m-1,n-1);
        return ans;
        
    }
};