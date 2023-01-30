// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int solve(string str, int n)
    {
        // add your code here
        vector<int> a;
        int count =0;
        for(auto it: str)
        {
            if(it==1)
            {
                count++;

            }
            else
            {
                if(count != 0)
                    a.push_back(count);
                count=0;
            }
        }

        int sum =0;
        for(auto it:a)
        {
            sum+=it;
        }
        int temp=sum/n;
        if(temp*n<sum)  temp++;
    
        int ans =0;
        for(auto it:a)
        {
            ans+=abs(it-temp);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin>>s;
     
        Solution ob;
        long long ans = ob.solve(s,n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends