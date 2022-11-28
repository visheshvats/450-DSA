#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& days, vector<int>& cost, int index)
{
	//bc
	if(index>=n)
		return 0;

	int option1 = cost[0]+solve(n, days, cost,index+1);

	int i;
	
	for(i=index ; i < n && days[i] < days[index] + 7 ; i++){}

	
	int option2 = cost[1]+solve(n, days, cost, i);


	for(i = index ; i < n && days[i] < days[index] + 30 ; i++){}

	int option3 = cost[2]+solve(n, days, cost, i);

	int ans  = min(option1, min(option2, option3));

	return ans;

}

int solveMem(int n, vector<int>& days, vector<int>& cost, int index, vector<int> &dp)
{
	//bc
	if(index>=n)
		return 0;

	if(dp[index]!=INT_MAX)
		return dp[index];
	

	int option1 = cost[0]+solveMem(n, days, cost,index+1,dp);

	int i;
	
	for(i=index ; i < n && days[i] < days[index] + 7 ; i++){}

	
	int option2 = cost[1]+solveMem(n, days, cost, i,dp);


	for(i = index ; i < n && days[i] < days[index] + 30 ; i++){}

	int option3 = cost[2]+solveMem(n, days, cost, i,dp);

	dp[index]  = min(option1, min(option2, option3));

	return dp[index];

}


int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
	vector<int> dp(n+1, INT_MAX);
	return solveMem(n, days, cost, 0, dp);
}