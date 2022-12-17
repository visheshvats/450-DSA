#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
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
        vector<int> in1;
        vector<int> in2;
        if(nums.size()==1)  return nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)    in1.push_back(nums[i]);
            if(i!=nums.size()-1)    in2.push_back(nums[i]);
        }
        return max(solvedp(in1), solvedp(in2));
        
        
    }
};