#include<bits/stdc++.h>

using namespace std;

int f(int i, vector<int> &arr, int k,vector<vector<int>> &dp)
{
    //bc
    if(k==0)    return 1;
    if(i<0) return 0;

 


    //rc
    if(dp[i][k]!=-1)    return dp[i][k];
    int nottaken =f(i-1,arr, k,dp);
    int taken =0;

    if(k>=arr[i])   taken = f(i-1, arr, k-arr[i],dp);

    return dp[i][k]=(taken+nottaken)%(int)(1e9+7);



}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
    int n = arr.size();
    vector<vector<int> > dp(n+1, vector<int>(k+1,-1));

    int ans = f(n-1, arr, k,dp);

    return ans;
    
}
