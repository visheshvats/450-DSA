// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//top-down approach

int knapSacks(int W, int wt[], int val[], int n, vector<vector<int>> &tt)
{
    //base condition
    if (n == 0)
        return tt[n][W] = 0;

    //recursive part
    if (tt[W][n] != -1)
    {
        return tt[W][n];
    }

    else
    {

        if (wt[n - 1] <= W)
        {
            return tt[W][n] = max(val[n - 1] + knapSacks(W - wt[n - 1], wt, val, n - 1, tt), knapSacks(W, wt, val, n - 1, tt));
        }
        else
        {
            return tt[W][n] = knapSacks(W, wt, val, n - 1, tt);
        }
    }
}

class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> tt(1001, vector<int>(1001, -1));

        int res = knapSacks(W,wt,val,n,tt);

        return res;
    }
};

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
} // } Driver Code Ends