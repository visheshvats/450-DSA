#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int n)
    {
        //bc
        if(n<0) return 0;
        //rc

        int ans = max(solve(nums,n-1),solve(nums,n-2)+nums[n]);
        return ans;

    }
    int solveMEM(vector<int> &nums, int n, vector<int> &dp)
    {
        //bc
        if(n<0) return 0;
        //rc

        if(dp[n]!=-1)   return dp[n];

        int ans = max(solveMEM(nums,n-1,dp),solveMEM(nums,n-2,dp)+nums[n]);
        return dp[n]=ans;

    }

    int solveTAB(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n,0);

        if(n==1)    return nums[0];
        if(n==2)    return max(nums[0], nums[1]);

        dp[0]= nums[0];
        dp[1]= max(nums[0], nums[1]);

        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1], dp[i-2]+nums[i]);
        }



        return dp[n-1];
    }

    int solveSO(vector<int> &nums)
    {
        int n = nums.size();
        // vector<int> dp(n,0);

        if(n==1)    return nums[0];
        if(n==2)    return max(nums[0], nums[1]);

        int a = nums[0];
        int b = max(nums[0], nums[1]);

        for(int i=2;i<n;i++)
        {
            b=max(b, a+nums[i]);
        }



        return b;
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        // int ans = solve(nums, n - 1);
        // int ans = solveMEM(nums, n - 1, dp);
        // int ans = solveTAB(nums);
        int ans = solveSO(nums);
        return ans;
    }
};