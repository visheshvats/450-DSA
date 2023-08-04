#include <bits/stdc++.h> 
using namespace std;

// int solve (int n, vector<int> &heights)
// {
//     //bc
//     if(n==1)    return 0;
//     if(n==2)    return abs(heights[0]-heights[1]);


//     //rc

//     int a = solve(n-1,heights)+abs(heights[n-1]-heights[n-2]);
//     int b = solve(n-2,heights)+abs(heights[n-1]-heights[n-3]);

//     return min(a,b);
// }
// int solveMEM (int n, vector<int> &heights, vector<int> &dp)
// {
//     //bc
//     if(n==1)    return 0;
//     if(n==2)    return abs(heights[0]-heights[1]);


//     //rc
//     if(dp[n]!=-1)   return dp[n];

//     int a = solveMEM(n-1,heights,dp)+abs(heights[n-1]-heights[n-2]);
//     int b = solveMEM(n-2,heights,dp)+abs(heights[n-1]-heights[n-3]);

//     return dp[n] = min(a,b);
// }
// int solveTAB(int n, vector<int> &heights)
// {
//     vector<int> dp(n+1,0);
//     dp[1]=0;
//     dp[2]=abs(heights[0]-heights[1]);

//     for(int i=3;i<n+1;i++)
//     {
//         int a = dp[i-1]+abs(heights[i-1]-heights[i-2]);
//         int b = dp[i-2]+abs(heights[i-1]-heights[i-3]);
//         dp[i]=min(a,b);
//     }
//     return dp[n];

// }

int solveSO(int n, vector<int> &heights)
{
    
    int prev2=0;
    int prev1 =abs(heights[0]-heights[1]);
    int curr;

    for(int i=3;i<n+1;i++)
    {
        int a = prev1+abs(heights[i-1]-heights[i-2]);
        int b = prev2+abs(heights[i-1]-heights[i-3]);
        curr=min(a,b);
        prev2=prev1;
        prev1=curr;
    }
    return curr;

}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    // int ans = solve(n, heights);
    // int ans = solveMEM(n, heights,dp);
    // int ans = solveTAB(n, heights);
    int ans = solveSO(n, heights);
    return ans;
}