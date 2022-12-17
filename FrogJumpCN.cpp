#include <bits/stdc++.h> 
using namespace std;


// int solveMem(int i, vector<int> &h, vector<int> &dp)
// {
//     //bc
//     if(i==0)
//         return 0;
//     if(i==1)
//         return abs(h[1]-h[0]);
//     //rc
//     if(dp[i]!=-1)
//         return dp[i];
//     int l2= abs(h[i-2]-h[i])+solveMem(i-2,h,dp);
//     int l1= abs(h[i-1]-h[i])+solveMem(i-1,h,dp);

//     return dp[i]=min(l2,l1);


// }
int solveSO(int n, vector<int> &h)
{
    // vector<int> dp(n,0);
    int l2=0;
    int l1=abs(h[1]-h[0]);
    int curr=0;
    for(int i=2;i<n;i++)
    {
        curr=min(abs(h[i-1]-h[i])+l1,abs(h[i-2]-h[i])+l2);
        l2=l1;
        l1=curr;
    }
    return curr;

}
// int solvedp(int n, vector<int> &h)
// {
//     vector<int> dp(n,0);
//     dp[0]=0;
//     dp[1]=abs(h[1]-h[0]);
//     for(int i=2;i<n;i++)
//     {
//         dp[i]=min(abs(h[i-1]-h[i])+dp[i-1],abs(h[i-2]-h[i])+dp[i-2]);
//     }
//     return dp[n-1];

// }
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    // vector<int> dp(n,-1);
    // int ans = solveMem(n-1,heights,dp);
    // int ans = solvedp(n,heights);
    int ans = solveSO(n,heights);
    

    return ans;
}