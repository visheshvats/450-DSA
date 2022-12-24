#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n, vector<vector<int>> & o)
    {
        if(m>=0&&n>=0&&o[m][n]==1) return 0;
        if(m==0&&n==0)  return 1;
        if(m<0||n<0) return 0;
    
        //rc
        int up = solve(m,n-1,o);
        int left = solve(m-1,n, o);
        return up+left;

    }
    int solveMEM(int m, int n, vector<vector<int>> & o, vector<vector<int>> &dp)
    {
        if(m>=0&&n>=0&&o[m][n]==1) return 0;
        if(m==0&&n==0)  return 1;
        if(m<0||n<0) return 0;
    
        //rc
        if(dp[m][n]!=-1) return dp[m][n];
        int up = solveMEM(m,n-1,o,dp);
        int left = solveMEM(m-1,n, o,dp);
        return dp[m][n]=up+left;

    }
    int solveTAB(vector<vector<int>> & o)
    {
        int m = o.size();
        int n = o[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=0&&j>=0&&o[i][j]==1) dp[i][j]=0;
                else if(i==0&&j==0) dp[i][j]=1;
                else
                {
                    int up=0;
                    int left =0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j]=up+left;

                }

            }
        }
        return dp[m-1][n-1];

    }
    int solveSO(vector<vector<int>> &o)
    {
        int m = o.size();
        int n = o[0].size();
        vector<int> d (n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> temp (n,0);
            for(int j=0;j<n;j++)
            {
                if(i>=0&&j>=0&&o[i][j]==1) temp[j]=0;
                else if(i==0&&j==0) temp[j]=1;
                else
                {
                    int up=0;
                    int left =0;
                    if(i>0) up = d[j];
                    if(j>0) left = temp[j-1];
                    temp[j]=up+left;

                }

            }
            d=temp;
        }

        return d[n-1];


    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // int m = obstacleGrid.size();
        // int n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n,-1));

        // int ans = solve(m-1,n-1, obstacleGrid);
        // int ans = solveMEM(m-1,n-1, obstacleGrid,dp);
        // int ans = solveTAB(obstacleGrid);
        int ans = solveSO(obstacleGrid);

        return ans;
        
    }
};