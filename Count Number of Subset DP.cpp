// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> k(n+1, (vector<int> (sum+1,0)));

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                {
                    k[i][j]=1;
                }
                else if(i==0)
                {
                    k[i][j]=0;

                }
                else if(arr[i-1]<=j)
                {
                    k[i][j]=(k[i-1][j]%1000000007+k[i-1][j-arr[i-1]]&1000000007)%1000000007;
                }
                
                else
                {
                    k[i][j]=k[i-1][j]%1000000007;
                }
                
            }
        }

        

        return (int)k[n][sum]%1000000007;

        
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends