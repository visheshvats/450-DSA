#include <bits/stdc++.h>
using namespace std;

int solveMEM(int i, vector<int> &nums, int target, int n,vector<vector<int>> &dp)
{
    // bc
    if (target == 0)
        return 1;
    else if (i == 0)
        return (target == nums[0]);

    // rc
    if(dp[i][target]!=-1)   return dp[i][target];
    int nottaken = solveMEM(i - 1, nums, target, n,dp);
    int taken = 0;
    if (target >= nums[i])
        taken = solveMEM(i - 1, nums, target - nums[i], n,dp);
    return dp[i][target]=taken + nottaken;
}
int findWays(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target+1,-1));
    int ans = solveMEM(n - 1, nums, target, n,dp);
    return ans;
}
