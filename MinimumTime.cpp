// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    int minTime(int n, vector<int> &time, vector<int> &search, int k) {
        // code here

        
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