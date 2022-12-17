#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int solve(int i, vector<int> &nums, vector<int> &dp)
    // {
    //     //bc
    //     if(i>=nums.size())
    //         return 0;


    //     //rc
    //     if(dp[i]!=-1)
    //         return dp[i];
    //     int s1=nums[i]+solve(i+2,nums,dp);
        
    //     int s3 = solve(i+1,nums,dp);
    //     int ans = max(s1,s3);

    //     return dp[i]=ans;

    // }

    int solvedp(vector<int> &nums)
    {
        int n= nums.size();
        // vector<int> dp(n,0);
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[1],nums[0]);
        // dp[n-1]=nums[n-1];
        // dp[n-2]=max(dp[n-1],nums[n-2]);
        int prev2=nums[n-1];
        int prev1=max(nums[n-1],nums[n-2]);
        int curr=0;

        for(int i=n-3;i>=0;i--)
        {
            int a=prev1;
            int b=0;
            if(i+2<n)
                b=nums[i]+prev2;
            curr=max(a,b);
            prev2=prev1;
            prev1=curr;
        }

        return curr;

    }
    int rob(vector<int>& nums) {
        // int ans =0;
        // vector<int> dp(nums.size(),-1);
        // ans = solve(0, nums,dp);
        int ans=solvedp(nums);

        return ans;
        
    }
};