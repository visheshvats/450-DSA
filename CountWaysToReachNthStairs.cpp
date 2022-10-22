#include <bits/stdc++.h> 

using namespace std;

int solve(int nStairs, int i, vector<int> &dp)
{
    if(i==nStairs)
        return 1;

    if(i>nStairs)
        return 0;

    if(dp[i]!=-1)
        return dp[i];

    return dp[i]=solve(nStairs,i+1)+solve(nStairs, i+2);
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int> dp(nStairs+1,-1);

    int ans = solve(nStairs,0,dp);

    return ans;
}