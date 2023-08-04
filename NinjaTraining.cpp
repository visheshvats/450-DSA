#include<bits/stdc++.h>;
using namespace std;

// int solveMEM(int n,int x, vector<vector<int>> &points,vector<vector<int>> &dp)
// {
//     //bc
//     if(n<0) return 0;



//     //rc
//     if(dp[n][x]!=-1)    return dp[n][x];

//     int ans=INT_MIN;
//     for(int i=0;i<3;i++)
//     {
//         if(i!=x)
//         {
//             ans=max(solveMEM(n-1,i,points,dp)+points[n][x],ans);
//         }
//     }

//     return dp[n][x] = ans;
// }

// int solveTAB(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>>dp(n,vector<int>(3,-1));

//     int ans=INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<3;j++)
//         {
//             int ans = INT_MIN;
//             for(int k=0;k<3;k++)
//             {
//                 if(k!=j&&i-1>=0)
//                 {
//                     ans = max(dp[i-1][k]+points[i][j],ans);
//                 }
//                 else if(k!=j&&i-1<=0)
//                 {
//                     ans=max(ans,points[i][j]);
//                 }
//             }

//             dp[i][j]=ans;


//         }
//     }

//     return max(dp[n-1][0],max(dp[n-1][2],dp[n-1][1]));

// }

int solveSO(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(3,-1));
    vector<int> dp1(n,-1);
    vector<int> dpcurr(n,-1);

    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            int ans = INT_MIN;
            for(int k=0;k<3;k++)
            {
                if(k!=j&&i-1>=0)
                {
                    ans = max(dp1[k]+points[i][j],ans);
                }
                else if(k!=j&&i-1<=0)
                {
                    ans=max(ans,points[i][j]);
                }
            }

            dpcurr[j]=ans;
            


        }
        dp1=dpcurr;
    }

    return max(dp1[0],max(dp1[2],dp1[1]));

}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // int ans = INT_MIN;
    // vector<vector<int>>dp(n,vector<int>(3,-1));
    // for(int i=0;i<3;i++)
    // {
    //     ans = max(ans, solveMEM(n-1,i,points,dp));
    // }

    // int ans = solveTAB(n,points);
    int ans = solveSO(n,points);
     
    return ans;
}