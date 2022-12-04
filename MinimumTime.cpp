// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    int dp(int i, int n, vector<int> &time, vector<int> &search, int k, vector<int> &d)
    {
        //bc
        if(i>=n)
            return 0;

        //rc
        if(d[i]!=-1)
            return d[i];
        
        int a = time[i]+dp(i+1, n,time, search,k,d);
        for(int j=1;j<=min(k,n-i);j++)
        {
            a=min(a,search[i]+dp(i+j,n,time, search,k,d));
        }

        return d[i]=a;



    }


    int minTime(int n, vector<int> &time, vector<int> &search, int k) {
        // code here
        vector<int> d(n+1,-1);
        int ans = dp(0, n, time, search, k,d);

        return ans;


    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> time(n);
        for(int i=0;i<n;i++){
            cin>>time[i];
        }
        
        
        vector<int> search(n);
        for(int i=0;i<n;i++){
            cin>>search[i];
        }
        
        
        int k;
        cin>>k;
        
        Solution obj;
        int res = obj.minTime(n, time, search, k);
        
        cout<<res<<endl;
        
    }
}
  // } Driver Code Ends