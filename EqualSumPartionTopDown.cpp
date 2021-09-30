// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }

        if (sum % 2 == 1)
        {
            return 0;
        }
        else
        {
            sum/=2;
            vector<vector<int>> k(N+1, (vector<int>(sum+1, 0)));

            for (int i = 0; i <= N; i++)
            {
                for (int j = 0; j <= sum; j++)
                {
                    if (i == 0)
                    {
                        k[i][j] = 0;
                    }
                    if (j == 0)
                    {
                        k[i][j] = 1;
                    }
                }
            }

            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= sum; j++)
                {
                    if (arr[i - 1] <= j)
                    {
                        k[i][j] = (k[i - 1][j] || k[i - 1][j - arr[i - 1]]);
                    }
                    else
                    {
                        k[i][j] = k[i - 1][j];
                    }
                }
            }

            return k[N][sum];
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
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends