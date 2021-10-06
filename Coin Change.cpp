// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {

        // code here.
        vector<vector<int>> k(m + 1, (vector<int>(n + 1, 0)));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                
                if (j == 0)
                    k[i][j] = 1;
                else if(i==0)
                    k[i][j]=0;
                else if (S[i-1] <= j)
                {
                    k[i][j] = 1+k[i][j - S[i-1]]+ k[i - 1][j];
                }
                else
                {
                    k[i][j] = k[i - 1][j];
                }
            }
        }

        return k[n][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends