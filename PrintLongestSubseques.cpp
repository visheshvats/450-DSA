#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solveTAB(int x, int y, string a, string b)
    {

        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        for (int i = 0; i <= x; i++)
        {
            for (int j = 0; j <= y; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    int ans = 0;
                    if (a[i - 1] == b[j - 1])
                    {
                        ans = dp[i - 1][j - 1];
                        ans++;
                    }
                    else
                    {
                        ans = max(dp[i-1][j],dp[i][j-1]);
                    }
                    dp[i][j] = ans;
                }
            }
        }

        return dp;

        
    }

string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	
	vector<vector<int>> dp = solveTAB(n,m,s1,s2);
	int x=dp.size();
	int y = dp[0].size();
	int i=n;
	int j=m;
	int ind = dp[x-1][y-1];
	string ans(ind, 0);

	// for(int i=0;i<x;i++)
	// {
	// 	for(int j=0;j<y;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	while(i>0&&j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			ans[ind-1]=s1[i-1];
			i--;
			j--;
			ind--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			i--;
		}
		else	j--;
	}


	return ans;
}