//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int f(int i, int p, int nums[],vector<vector<int>> &dp,int n)
    {
        //bc
        if(i==n)    return 0;


        //rc
        if(dp[i][p+1]!=-1)  return dp[i][p+1];
        int nottake = f(i+1,p,nums,dp,n);
        int take = -1e9;
        if(p==-1||nums[p]<nums[i])
        {
            take=1+f(i+1,i,nums,dp,n);
        }



        return dp[i][p+1]=max(take, nottake);


    }
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	   // int n= nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ans = f(0,-1,arr,dp,n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends