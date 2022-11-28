// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isPrime(int n)
    {
        
        if (n <= 1)
            return false;

        
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;

        return true;
    }

    int solve(int N, string S)
    {
        // code here
        unordered_set<char> mp;
        int n = N;
        int ans=0;
        for (int i = 0; i < n; i++)
        {
            mp.insert(S[i]);
            if (i > 0 && i % 2 == 1&&isPrime(mp.size()))
            {
                ans++;
            }
        }
        return ans;
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
        string S;
        cin >> N >> S;

        Solution obj;
        int res = obj.solve(N, S);

        cout << res << "\n";
    }
}
// } Driver Code Ends