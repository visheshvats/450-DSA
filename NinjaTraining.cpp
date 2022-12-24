#include<bits/stdc++.h>
using namespace std;

// int solve(int day, int last, vector<vector<int>> &points, int n, vector<vector<int>> &dp)
// {
//     //bc
//     if(day==0)
//     {
//         int man=0;
//         for(int i=0;i<3;i++)
//         {
//             if(i!=last)
//             {
//                 man=max(man, points[0][i]);
//             }
//         }

//         return man;
//     }

//     //rc
//     if(dp[day][last]!=-1)
//         return dp[day][last];
//     int ans =0;
//     for(int i=0;i<3;i++)
//     {
//         if(i!=last)
//         {
//             int t = points[day][i]+solve(day-1,i,points, n,dp);
//             ans=max(t,ans);
//         }
//     }

//     return dp[day][last]=ans;
// }

int solveTAB(int n, vector<vector<int>> &p)
{
    vector<vector<int>> dp(n, vector<int> (4,-1));

    dp[0][0]=max(p[0][1],p[0][2]);
    dp[0][1]=max(p[0][0],p[0][2]);
    dp[0][2]=max(p[0][1],p[0][0]);
    dp[0][3]=max(p[0][1],max(p[0][0],p[0][2]));

    for(int day=1;day<n;day++)
    {
        for(int last=0;last<=3;last++)
        {
            dp[day][last]=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int t = p[day][task]+dp[day-1][task];
                    dp[day][last]=max(t,dp[day][last]);
                }
            }
        }
    }  

    return dp[n-1][3];  



}

int solveSO(int n, vector<vector<int>> &p)
{
    // vector<vector<int>> dp(n, vector<int> (4,-1));
    vector<vector<int>> dp (2, vector<int> (4,-1));

    dp[0][0]=max(p[0][1],p[0][2]);
    dp[0][1]=max(p[0][0],p[0][2]);
    dp[0][2]=max(p[0][1],p[0][0]);
    dp[0][3]=max(p[0][1],max(p[0][0],p[0][2]));

    for(int day=1;day<n;day++)
    {
        for(int last=0;last<=3;last++)
        {
            int t=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int t = p[day][task]+dp[0][task];
                    dp[1][last]=max(t,dp[1][last]);
                }
            }
            
        }
        dp[0]=dp[1];
    }  

    return dp[0][3];
}



int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // vector<vector<int>> dp(n,vector<int>(4,-1));
    // int ans=solve(n-1,3, points, n,dp);
    // int ans=solveTAB(n, points);
    int ans=solveSO(n, points);

    return ans;
}