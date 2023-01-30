#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // bool solveMEM(int i, vector<int> &nums, int n, vector<bool> &dp)
    // {
    //     // bc
    //     if (i == n - 1)
    //         return 1;
    //     if (i >= n)
    //         return 0;
    //     // rc
    //     if (dp[i] != -1)
    //         return dp[i];
    //     bool ans = 0;
    //     for (int a = 1; a <= nums[i]; a++)
    //     {
    //         ans = ans | solveMEM(i + a, nums, n, dp);
    //     }

    //     return dp[i] = ans;
    // }
    bool solveTAB(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                dp[i] = 1;
            }
            else
            {
                bool ans = 0;
                for (int a = 1; a <= nums[i]; a++)
                {
                    if(i+a<n)
                        ans = ans | dp[i + a];
                }

                dp[i] = ans;
            }
        }
        return dp[n-1];
    }
    bool canJump(vector<int> &nums)
    {
        // vector<bool> dp(nums.size(), 0);
        // bool ans = solveMEM(0, nums, nums.size(), dp);
        bool ans = solveTAB(nums);
        return ans;
    }
};