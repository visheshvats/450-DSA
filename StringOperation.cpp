// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int flip(int binaryDigit)
    {
        return binaryDigit == 0 ? 1 : 0;
    }
    int getFlipCountToAlternateString(vector<int> binary, int expected)
    {
        int flipCount = 0;
        for (int i = 0; i < binary.size(); i++)
        {
            if (binary[i] != expected)
            {
                flipCount++;
            }
            expected = flip(expected);
        }
        return flipCount;
    }
    int solve(int n, string s)
    {
        // code here
        vector<int> le(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                le[i] = 1;
            }
        }
        return min(getFlipCountToAlternateString(le, 0), getFlipCountToAlternateString(le, 1));
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
        string s;
        cin >> s;
        Solution obj;
        int ans = obj.solve(n, s);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends