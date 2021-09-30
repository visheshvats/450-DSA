// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    bool isSubsetSum(int N, int arr[], int sum)
    {
        // code here
        vector<vector<int>> k(N + 1, (vector<int>(sum + 1, -1)));
        return res(N, arr, sum, k);
    }

 bool res(int N, int arr[], int sum, vector<vector<int>> &k)
    {
        //base condition
        if (sum == 0)
            return true;

        if (N == 0)
            return false;

        //recursive part
        if (k[N][sum] != -1)
            return k[N][sum];
        else
        {
            if(arr[N-1]<=sum)
                return k[N][sum]=(res(N-1,arr,sum,k)||res(N-1,arr,sum-arr[N-1],k));
            else
                return k[N][sum]=res(N-1,arr,sum,k);
        }
    }   
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends