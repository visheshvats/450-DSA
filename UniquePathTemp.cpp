#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int m, int n)
    {
        // bc
        if (m == 0 && n == 0)
        {
            return 1;
        }
        if (m < 0 || n < 0)
        {
            return 0;
        }

        // rc
        int left = solve(m - 1, n);
        int down = solve(m, n - 1);
        return left + down;
    }

    int solveMEM(int m, int n, vector<vector<int>> &dp)
    {
        // bc
        if (m == 0 && n == 0)
        {
            return 1;
        }
        if (m < 0 || n < 0)
        {
            return 0;
        }

        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }

        // rc
        int left = solveMEM(m - 1, n, dp);
        int down = solveMEM(m, n - 1, dp);
        return dp[m][n] = left + down;
    }

    int solveTAB(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[0][0]=1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[0][0] = 1;
                else
                {

                    int left = 0;
                    if (i - 1 >= 0)
                        left = dp[i - 1][j];
                    int down = 0;
                    if (j - 1 >= 0)
                        down = dp[i][j - 1];
                    dp[i][j] = left + down;
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    int solveSO(int m, int n)
    {
        
        vector<int> prev(n, 0);
        // dp[0][0]=1;
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);

            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    curr[0] = 1;
                else
                {

                    int left = 0;
                    if (i - 1 >= 0)
                        left = prev[j];
                    int down = 0;
                    if (j - 1 >= 0)
                        down = curr[j - 1];
                    curr[j] = left + down;
                }
            }
            prev=curr;
        }

        return prev[n - 1];
    }

    int uniquePaths(int m, int n)
    {

        // int ans = solve(m-1, n-1);
        // vector<vector<int>> dp(m, vector<int>(n,-1));

        // int ans = solveMEM(m-1, n-1, dp);
        // int ans = solveTAB(m, n);
        int ans = solveSO(m, n);

        return ans;
    }
};

