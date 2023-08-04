//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int n, long long int k) {
    vector<long long> ans;
    // 1 2 3 4 5 6 7 8 9

    for(long long int i=0;i<n-k+1;i++)
    {
        bool flag=0;
        for(long long int j=0;j<k;j++)
        {
            if(A[i+j]<0)
            {
                ans.push_back( A[i+j]);
                break;
            }
        }

        if(!flag)
        {
            ans.push_back(0);
        }
    }

    return ans;

                                            
                                                 
 }