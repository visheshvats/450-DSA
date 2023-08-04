#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& nums, int n)
{
	// int n= nums.size();
        int sum =0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        vector<bool> prev(sum+1,0);
        // vector<vector<bool>> dp (n,vector<bool>(sum+1,0));

        for(int i=0;i<n;i++)
        {
        vector<bool> curr(sum+1,0);
            for(int j=0;j<=sum;j++)
            {
                if(j==0)    curr[j]=1;
                else if(i==0)   curr[j]=nums[i]==j;
                else
                {
                    bool take =false;
                    if(nums[i]<=j)
                    take = prev[j-nums[i]];
                    bool nottake = prev[j];
                    curr[j]=take|nottake;
                }
            }
            prev=curr;
        }

        int che=0;
        if(sum%2==0)
            che=sum/2;
        else
            che=(sum+1)/2;

        int ans =0;

        for(int i=0;i<=che;i++)
        {
            if(prev[i]==1)   ans = i;
        }


        return abs(sum -(2*ans));
}
