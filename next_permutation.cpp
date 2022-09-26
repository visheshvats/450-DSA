// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int k,l;
        for(int i=N-2;i>=0;i--)
        {
            if(arr[i]<arr[i+1])
                break;
        }
        if(k<0)
            reverse(arr.begin(),arr.end());
        else{
            for(l=N-1;l<k;l--)
            {
                if(arr[l]>arr[k])
                    break;
            }

            swap(arr[l],arr[k]);
            reverse(arr.begin()+k+1,arr.end());
        }

        return arr;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends