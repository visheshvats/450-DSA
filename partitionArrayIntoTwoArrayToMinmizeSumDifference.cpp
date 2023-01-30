#include <bits/stdc++.h>
using namespace std;
int solveSO(int n, int k, vector<int> &arr)
{
    vector<bool> dp(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        vector<bool> temp(k + 1, 0);
        for (int j = 0; j < k + 1; j++)
        {
            if (j == 0)
            {
                temp[j] = 1;
            }
            else if (i == 0)
            {
                temp[j] = j == arr[0];
            }
            else
            {
                bool taken = false;
                if (arr[i] <= j)
                    taken = dp[j - arr[i]];
                bool nottaken = dp[j];

                temp[j] = taken | nottaken;
            }
        }
        dp = temp;
    }
    int i = k;
    for (; i >= 0; i--)
    {
        if (dp[i] == 1)
            break;
    }

    return i;

    
}


int minSubsetSumDifference(vector<int> &nums, int n)
{
    int sum = 0;
    for (auto it : nums)
    {
        sum += it;
    }
    int ans = solveSO(nums.size(), sum / 2, nums);
    return sum - (2 * ans);
}
