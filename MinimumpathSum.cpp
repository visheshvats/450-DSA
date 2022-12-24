#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveMEM(int m, int n, vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        //bc
        if(m<0||n<0)    return INT_MAX;
        if(m==0&&n==0){
            return grid[0][0];
        }
        //rc
        if(dp[m][n]!=-1)
            return dp[m][n];
        int up= solveMEM(m-1,n,grid,dp);
        int left=solveMEM(m,n-1,grid,dp);
        int aa= min(up,left);

        return dp[m][n]=aa+grid[m][n];
    }
    int solveTAB(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n= grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0) dp[i][j]=grid[0][0];
                else
                {
                    int up=INT_MAX;
                    int left=INT_MAX;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                    int aa = min(up,left);
                    dp[i][j]=aa+grid[i][j];


                }
            }
        }

        return dp[m-1][n-1];
    }
    int solveSO(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n= grid[0].size();

        vector<int> dp(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0) temp[j]=grid[0][0];
                else
                {
                    int up=INT_MAX;
                    int left=INT_MAX;
                    if(i>0) up = dp[j];
                    if(j>0) left = temp[j-1];

                    int aa = min(up,left);
                    temp[j]=aa+grid[i][j];


                }
            }
            dp=temp;
        }

        return dp[n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        // int m = grid.size();
        // int n = grid[0].size();
        
        // vector<vector<int>> dp(m, vector<int> (n,-1));

        int ans = 0;
        // ans=solveMEM(m-1,n-1,grid,dp);
        // ans=solveTAB(grid);
        ans=solveSO(grid);

        return ans;
        
    }
};