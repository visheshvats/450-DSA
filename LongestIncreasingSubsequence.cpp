#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int f(int i, int p, vector<int> &nums,vector<vector<int>> &dp)
    {
        //bc
        if(i==nums.size())    return 0;


        //rc
        if(dp[i][p+1]!=-1)  return dp[i][p+1];
        int nottake = f(i+1,p,nums,dp);
        int take = INT_MIN;
        if(p==-1||nums[p]<nums[i])
        {
            take=1+f(i+1,i,nums,dp);
        }



        return dp[i][p+1]=max(take, nottake);


    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ans = f(0,-1,nums,dp);
        return ans;
        
    }
};