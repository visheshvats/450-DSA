#include <bits/stdc++.h> 
using namespace std;

// int solve(vector<int> &nums,int n)
// {
//     //bc
//     if(n==0)    return 0;
//     if(n==1)    return nums[0];
//     if(n==2)    return max(nums[0],nums[1]);

//     //rc

//     int ans = max(nums[n-1]+solve(nums,n-2),solve(nums,n-1));

//     return ans;




// }

// int solveMEM(vector<int> &nums,int n,vector<int> &dp)
// {
//     //bc
//     if(n==0)    return 0;
//     if(n==1)    return nums[0];
//     if(n==2)    return max(nums[0],nums[1]);

//     //rc

//     if(dp[n]!=-1)   return dp[n];

//     return dp[n] = max(nums[n-1]+solveMEM(nums,n-2,dp),solveMEM(nums,n-1,dp));

    



// }

// int solveTAB(vector<int> &nums, int n)
// {
//     vector<int> dp(n+1,0);
//     dp[1]=nums[0];
//     dp[2]=max(nums[0],nums[1]);

//     for(int i=3;i<=n;i++)
//     {
//         dp[i]=max(nums[n-1]+dp[i-2],dp[i-1]);
//     }
//     return dp[n+1];
// }
int solveSO(vector<int> &nums, int n)
{
    // vector<int> dp(n+1,0);
    int a=nums[0];
    int b=max(nums[0],nums[1]);
    int c;

    for(int i=3;i<=n;i++)
    {
        c =max(nums[n-1]+a,b);
        a=b;
        b=c;
    }
    return b;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    // vector<int> dp(n+1,-1);
    // int ans= solve(nums,n);
    // int ans= solveMEM(nums,n,dp);
    // int ans= solveTAB(nums,n);
    int ans= solveSO(nums,n);
    return ans;
}