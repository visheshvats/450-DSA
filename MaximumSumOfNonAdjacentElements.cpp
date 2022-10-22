#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int i)
{
    // BC
    if (i == 1)
        return nums[0];
    if (i < 0)
        return 0;

    // RC
    int ans = max(solve(nums, i - 2) + nums[i - 1], solve(nums, i - 1));

    return ans;
}

int solveMem(vector<int> &nums, int i, vector<int> &dp)
{
    // BC
    if (i == 1)
        return nums[0];
    if (i <= 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    // RC
    dp[i] = max(solve(nums, i - 2) + nums[i - 1], solve(nums, i - 1));

    return dp[i];
}

int solveTab(vector<int> &nums, int n)
{
    vector<int> dp(n + 1, -1);

    dp[1] = nums[0];
    dp[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }

    return dp[n];
}
int solveSO(vector<int> &nums, int n)
{

    int prev = nums[0];
    int prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr = max(prev2 + nums[i - 1], prev);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.

    int n = nums.size();

    // vector<int> dp(n+1,-1);

    int ans = solveSO(nums, n);

    return ans;
}