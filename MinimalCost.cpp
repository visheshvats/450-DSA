    #include<bits/stdc++.h>
    using namespace std;

    // int solve (int n, int k, vector<int> &height)
    // {
    //     //bc
    //     if(n==1)    return 0;



    //     //rc
    //     int mini = INT_MAX;

    //     for(int i=1;i<=k;i++)
    //     {
    //         int temp = INT_MAX;
    //         if(n-i-1>=0)
    //             temp = solve(n-i,k,height)+abs(height[n-1]-height[n-i-1]);
            
    //         mini=min(mini,temp);

    //     }

    //     return mini;




    // }

    // int solveMEM (int n, int k, vector<int> &height, vector<int> &dp)
    // {
    //     //bc
    //     if(n==1)    return 0;



    //     //rc
    //     if(dp[n]!=-1)   return dp[n];
    //     int mini = INT_MAX;

    //     for(int i=1;i<=k;i++)
    //     {
    //         int temp = INT_MAX;
    //         if(n-i-1>=0)
    //             temp = solveMEM(n-i,k,height,dp)+abs(height[n-1]-height[n-i-1]);
            
    //         mini=min(mini,temp);

    //     }

    //     return dp[n]= mini;




    // }

    int solveTAB (int n, int k, vector<int> &height)
    {
        vector<int> dp(n+1,0);

        dp[1]=0;
        // //bc
        // if(n==1)    return 0;



        //rc
        // if(dp[n]!=-1)   return dp[n];
        for(int j=2;j<=n;j++)
        {
            dp[j] = INT_MAX;

            for(int i=1;i<=k;i++)
            {
                int temp = INT_MAX;
                if(j-i-1>=0)
                    temp = dp[j-i]+abs(height[j-1]-height[j-i-1]);
                
                dp[j]=min(dp[j],temp);

            }

        }

        return dp[n];




    }

    int minimizeCost(int n, int k, vector<int> &height){
        // Write your code here.
        // vector<int> dp(n+1,-1);

        // int ans = solve(n,k,height);
        // int ans = solveMEM(n,k,height,dp);
        int ans = solveTAB(n,k,height);
        return ans;
    }
