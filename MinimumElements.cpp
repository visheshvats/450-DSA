#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &num, int x)
{
    // BC
    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;

    // RC
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve(num, x - num[i]);
        if (ans != INT_MAX)
            mini = min(ans + 1, mini);
    }

    return mini;
}
int solveMem(vector<int> &num, int x, vector<int> &dp)
{
    // BC
    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;

    // RC
    if (dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveMem(num, x - num[i], dp);
        if (ans != INT_MAX)
            mini = min(ans + 1, mini);
    }
    return dp[x] = mini;
}

int solveTab(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {

        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
                dp[i] = min(dp[i], dp[i - num[j]] + 1);
        }
    }

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    // vector<int> dp(x+1,-1);
    int ans = solveTab(num, x);
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}