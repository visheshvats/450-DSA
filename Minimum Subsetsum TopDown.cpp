// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum = sum +arr[i];
        }

        vector<vector<int>> k(n+1, (vector<int> (sum+1,-1)));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0)
                {
                    k[i][j]=0;
                }
                if(j==0)
                {
                    k[i][j]=1;

                }

                

            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                {
                    k[i][j]=(k[i-1][j]||k[i-1][j-arr[i-1]]);
                }
                else
                {
                    k[i][j]=k[i-1][j];
                }
            }
        }

        int res=99999999;
        vector<int> rr;
        for(int i=0;i<=(sum/2);i++)
        {
            if(k[n][i]==1)
            {
                rr.push_back(i);
            }
        }

        for(int i=0;i<rr.size();i++)
        {
            res=min(res,sum-(2*rr[i]));
        }

        return res;
	    
	    
	} 
};


// { Driver Code Starts.
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends