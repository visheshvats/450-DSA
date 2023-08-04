//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, int arr[],int N,vector<vector<int>> &dp)
    {
        //bc
        if(i==j)    return 0;

        //rc
        if(dp[i][j]!=-1)    return dp[i][j];
        int mini=INT_MAX;
        for(int x=i;x<j;x++)
        {
            mini=min(mini, arr[i-1]*arr[x]*arr[j]
            +f(i,x,arr,N,dp)+f(x+1,j,arr,N,dp));

        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        int ans = f(1,N-1,arr,N,dp);
        return ans;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends