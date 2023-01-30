#include<bits/stdc++.h>
using namespace std;

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
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        for(auto it:nums)
        {
            sum+=it;
        }
        if(sum%1)
            return false;
        bool ans = solveSO(n,sum/2,nums);
        return ans;
        
    }
};