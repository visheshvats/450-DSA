// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:\

    int ss(int N, int W, int val[], int wt[], vector<vector<int>> &k)
    {
        //base condition
        if(W==0||N==0)
            return 0;

        //recursive Condition

        if(k[N][W]!=-1)
            return k[N][W];
        if(wt[N-1]<=W)
        {
            return k[N][W]=max(val[N-1]+ss(N,W-wt[N-1],val,wt,k),ss(N-1,W,val,wt,k));
        }
        else
        {
            return k[N][W]=ss(N-1,W,val,wt,k);
        }
        


    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> k(N+1, (vector<int> (W+1,-1)));

        return ss(N,W,val,wt,k);


    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends