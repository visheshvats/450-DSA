#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{

    //bc
    if(n==0)
    {
        if(weight[n]<=maxWeight)
            return value[n];
        else
            return 0;
    }

    //RC

    if(weight[n]<=maxWeight)
        return max(solve(weight, value, n-1, maxWeight-weight[n])+value[n], solve(weight, value, n-1, maxWeight));
    else
        return solve(weight, value, n-1, maxWeight);

}
int solveMem(vector<int> &weight, vector<int> &value, int n, int maxWeight , vector<vector<int>> &dp)
{

    //bc
    if(n==0)
    {
        if(weight[n]<=maxWeight)
            return value[n];
        else
            return 0;
    }

    if(dp[n][maxWeight]!=-1)
        return dp[n][maxWeight];

    //RC

    if(weight[n]<=maxWeight)
        return dp[n][maxWeight] =  max(solveMem(weight, value, n-1, maxWeight-weight[n],dp)+value[n], solveMem(weight, value, n-1, maxWeight,dp));
    else
        return dp[n][maxWeight] = solveMem(weight, value, n-1, maxWeight,dp);

}


int solveTabSO(vector<int> &weight, vector<int> &value, int n, int maxWeight )
{
    // vector<vector<int>> dp(n, vector<int>(maxWeight+1,0));
    vector<int> prev(maxWeight+1, 0);
    vector<int> curr(maxWeight+1, 0);

    
    for(int i=0;i<=maxWeight;i++)
    {
        if(weight[0]<=i)
            prev[i]=value[0];
        else
            prev[i]=0;
    }   

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            if(weight[i]<=j)
                curr[j] = max(prev[j-weight[i]]+value[i], prev[j]);
            else
                curr[j] = prev[j];
        }

        prev=curr;
    }

    return prev[maxWeight];


    
}

int solveTabUSO(vector<int> &weight, vector<int> &value, int n, int maxWeight )
{
    // vector<vector<int>> dp(n, vector<int>(maxWeight+1,0));
    // vector<int> prev(maxWeight+1, 0);
    vector<int> curr(maxWeight+1, 0);

    
    for(int i=0;i<=maxWeight;i++)
    {
        if(weight[0]<=i)
            curr[i]=value[0];
        else
            curr[i]=0;
    }   

    for(int i=1;i<n;i++)
    {
        for(int j=maxWeight;j>=0;j--)
        {
            if(weight[i]<=j)
                curr[j] = max(curr[j-weight[i]]+value[i], curr[j]);
            else
                curr[j] = curr[j];
        }

        
    }

    return curr[maxWeight];


    
}



int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    // vector<vector<int>> dp(n, vector<int>(maxWeight+1,-1));

    return solveTabUSO(weight, value, n, maxWeight);
}