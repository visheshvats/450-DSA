// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


 // } Driver Code Ends
class Solution {
  public:
  int ceilSearch(vector<int> &arr, int low, int high, int x)
{
     
    int i;
     
    
    if(x <= arr[low])
        return low;
     
    
    for(i = low; i < high; i++)
    {
        if(arr[i] == x)
        return i;
     
        
        if(arr[i] < x && arr[i+1] >= x)
        return i+1;
    }    
     
    
    return -1;
}
    vector<int> findMin(int n, int q, vector<int> &gain, vector<int> &loss, vector<int> &query) {
        // code here
        vector<int> res(n,0);
        for(int i=0;i<n;i++)
        {
            if(gain[i]-loss[i]>0)
                res.push_back(gain[i]-loss[i]);
        }
        sort(res.begin(), res.end());
        int tt= res.size();
        for(int i=tt-2;i>0;i--)
        {
            res[i]=res[i]+res[i+1];
        }
        reverse(res.begin(), res.end());
        vector<int> ans(q,-1);
        for(int i =0;i<q;i++)
        {
            int t = ceilSearch(res, 0, n-1, query[i]);
            if(t!=-1)
                ans[i]=t+1;
        }
        return ans;

    }
};


// { Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int q;
        scanf("%d",&q);
        
        
        vector<int> gain(n);
        Array::input(gain,n);
        
        
        vector<int> loss(n);
        Array::input(loss,n);
        
        
        vector<int> query(q);
        Array::input(query,q);
        
        Solution obj;
        vector<int> res = obj.findMin(n, q, gain, loss, query);
        
        Array::print(res);
        
    }
}
  // } Driver Code Ends