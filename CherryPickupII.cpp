#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int solveMEM(int i, int j1, int j2, vector<vector<int>> &grid, int row, int col, vector<vector<vector<int>>> &dp)
    // {
    //     // bc
    //     if (j1 >= col || j2 >= col || j1 < 0 || j2 < 0)
    //         return INT_MIN;
    //     if (i == row - 1)
    //     {
    //         if (j1 == j2)
    //             return grid[i][j1];
    //         else
    //             return grid[i][j1] + grid[i][j2];
    //     }

    //     // rc
    //     if (dp[i][j1][j2] != -1)
    //         return dp[i][j1][j2];
    //     int ans = 0;
    //     for (int a = -1; a < 2; a++)
    //     {
    //         for (int b = -1; b < 2; b++)
    //         {
    //             ans = max(ans, solveMEM(i + 1, j1 + a, j2 + b, grid, row, col, dp));
    //         }
    //     }

    //     if (j1 == j2)
    //         ans = ans + grid[i][j1];
    //     else
    //         ans = grid[i][j1] + grid[i][j2] + ans;

    //     return dp[i][j1][j2] = ans;
    // }
    // int solveTAB(vector<vector<int>> &grid)
    // {
    //     int row = grid.size();
    //     int col = grid[0].size();
    //     vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, 0)));
    //     for (int i = row - 1; i >= 0; i--)
    //     {
    //         for (int j1 = 0; j1 < col; j1++)
    //         {
    //             for (int j2 = 0; j2 < col; j2++)
    //             {
    //                 if (i == row - 1)
    //                 {
    //                     if (j1 == j2)
    //                         dp[i][j1][j2] = grid[i][j1];
    //                     else
    //                         dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
    //                 }
    //                 else
    //                 {
    //                     int ans = 0;
    //                     for (int a = -1; a < 2; a++)
    //                     {
    //                         for (int b = -1; b < 2; b++)
    //                         {
    //                             if (j1 + a < col && j2 + b < col && j2 + b >= 0 && j1 + a >= 0)
    //                                 ans = max(ans, dp[i + 1][j1 + a][j2 + b]);
    //                         }
    //                     }
    //                     if (j1 == j2)
    //                         ans = ans + grid[i][j1];
    //                     else
    //                         ans = grid[i][j1] + grid[i][j2] + ans;

    //                     dp[i][j1][j2] = ans;
    //                 }
    //             }
    //         }
    //     }

    //     return dp[0][0][col-1];
    // }
    int solveSO(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(col, vector<int>(col, 0));
        vector<vector<int>> curr(col, vector<int>(col, 0));
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j1 = 0; j1 < col; j1++)
            {
                for (int j2 = 0; j2 < col; j2++)
                {
                    if (i == row - 1)
                    {
                        if (j1 == j2)
                            curr[j1][j2] = grid[i][j1];
                        else
                            curr[j1][j2] = grid[i][j1] + grid[i][j2];
                        
                        
                    }
                    else
                    {
                        int ans = 0;
                        for (int a = -1; a < 2; a++)
                        {
                            for (int b = -1; b < 2; b++)
                            {
                                if (j1 + a < col && j2 + b < col && j2 + b >= 0 && j1 + a >= 0)
                                    ans = max(ans, dp[j1 + a][j2 + b]);
                            }
                        }
                        if (j1 == j2)
                            ans = ans + grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2] + ans;

                        curr[j1][j2] = ans;

                    
                    }
                }
            }
            dp=curr;
        }

        return dp[0][col-1];
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        // int row = grid.size();
        // int col = grid[0].size();
        // vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));

        // int ans = solveMEM(0, 0, col - 1, grid, row, col, dp);
        // int ans = solveTAB(grid);
        int ans = solveSO(grid);

        return ans;
    }
};