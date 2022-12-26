#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int solve(int i, int j, vector<vector<int>> &m, int n)
    // {
    //     //bc
    //     if(i==n-1&&j>=0&&j<n) return m[i][j];
    //     if(j>=n||j<0) return INT_MAX;

    //     //rc
    //     int a = solve(i+1,j,m,n);   
    //     int b =  solve(i+1,j+1,m,n);
    //     int c = solve(i+1,j-1,m,n);
    //     int ans  = min(a,min(b,c));
    //     ans+=m[i][j];
    //     return ans;
    // }
    // int solveMEM(int i, int j, vector<vector<int>> &m, int n,vector<vector<int>> &dp)
    // {
    //     //bc
    //     if(i==n-1&&j>=0&&j<n) return m[i][j];
    //     if(j>=n||j<0) return INT_MAX;

    //     //rc
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int a = solveMEM(i+1,j,m,n,dp);   
    //     int b =  solveMEM(i+1,j+1,m,n,dp);
    //     int c = solveMEM(i+1,j-1,m,n,dp);
    //     int ans  = min(a,min(b,c));
    //     ans+=m[i][j];
    //     return dp[i][j]=ans;
    // }
    // int solveTAB(vector<vector<int>> &m)
    // {
    //     int n = m.size();

    //     vector<vector<int>> dp(n, vector<int>(n,-1));
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         for(int j=n-1;j>=0;j--)
    //         {
    //             if(i==n-1)
    //             {
    //                 dp[i][j]=m[i][j];
    //             }
    //             else
    //             {
    //                 int a = dp[i+1][j];   
    //                 int b =  INT_MAX;
    //                 int c = INT_MAX;
    //                 if(j<n-1)
    //                 {
    //                     b=dp[i+1][j+1];
                        
    //                 }
    //                 if(j!=0)
    //                 {
    //                     c=dp[i+1][j-1];
    //                 }
    //                 dp[i][j]  = min(a,min(b,c));
    //                 dp[i][j]+=m[i][j];

    //             }
    //         }
    //     }
    //     int ans = INT_MAX;
    //     for(int i=0;i<n;i++)
    //     {
    //         ans=min(ans, dp[0][i]);
    //     }

    //     return ans;
    // }
    int solveSO(vector<vector<int>> &m)
    {
        int n = m.size();

        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int> temp(n,0);
            for(int j=n-1;j>=0;j--)
            {
                if(i==n-1)
                {
                    temp[j]=m[i][j];
                }
                else
                {
                    int a = dp[j];   
                    int b =  INT_MAX;
                    int c = INT_MAX;
                    if(j<n-1)
                    {
                        b=dp[j+1];
                        
                    }
                    if(j!=0)
                    {
                        c=dp[j-1];
                    }
                    temp[j]  = min(a,min(b,c));
                    temp[j]+=m[i][j];

                }
            }
            dp=temp;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans, dp[i]);
        }

        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int ans = INT_MAX;
        
        // for(int i=0;i<n;i++)
        // {
        //     vector<vector<int>> dp(n,vector<int>(n,-1));
        //     int temp  = solveMEM(0,i,matrix,n,dp);
        //     ans=min(temp,ans);

        // }
        // int ans = solveTAB(matrix);
        int ans = solveSO(matrix);
        return ans;
        
    }
};
