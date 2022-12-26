#include <bits/stdc++.h>
using namespace std;

// bool solveMEM(int i, int t, vector<int> &nums, vector<vector<int>> &dp)
// {
//     // bc

//     if (t == 0)
//         return 1;
//     if (i == 0)
//         return (t == nums[0]);

//     // rc
//     if (dp[i][t] != -1)
//         return dp[i][t];
//     bool taken = false;
//     if (nums[i] <= t)
//         taken = solveMEM(i - 1, t - nums[i], nums, dp);
//     bool nottaken = solveMEM(i - 1, t, nums, dp);

//     return dp[i][t] = taken | nottaken;
// }
// bool solveTAB(int n, int k, vector<int> &arr)
// {
//     vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < k + 1; j++)
//         {
//             if (j == 0)
//             {
//                 dp[i][j] = 1;
//             }
//             else if (i == 0)
//             {
//                 dp[i][j] = j == arr[0];
//             }
//             else
//             {
//                 bool taken = false;
//                 if (arr[i] <= j)
//                     taken = dp[i - 1][j - arr[i]];
//                 bool nottaken = dp[i - 1][j];

//                 dp[i][j] = taken | nottaken;
//             }
//         }
//     }

//     return dp[n-1][k];
// }
bool solveSO(int n, int k, vector<int> &arr)
{
    vector<bool> dp(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        vector<bool> temp(k+1,0);
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
        dp=temp;
    }

    return dp[k];
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // vector<vector<int>> dp(n, vector<int> (k+1,-1));
    // int ans = solveMEM(n-1,k,arr,dp);
    // bool ans = solveTAB(n, k, arr);
    bool ans = solveSO(n, k, arr);
    return ans;
}