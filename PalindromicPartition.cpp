//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(int i, int j, string str)
    {
        while(i<=j)
        {
            if(str[i]!=str[j])  return false;
            i++;
            j--;

        }
        return true;
    }
    int f(int i, string str,int n,vector<int> &dp)
    {
        //bc
        if(i==n)    return 0;



        //rc
        if(dp[i]!=-1)   return dp[i];
        int mini=1e9;
        for(int j=0;j<n;j++)
        {
            if(isPalindrome(i,i+j,str))
            {
                mini=min(mini, 1+f(i+1,str,n,dp));
            }
        }
        return dp[i]=mini;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n= str.size();
        vector<int> dp(n+1,-1);
        int ans = f(0,str,n,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends