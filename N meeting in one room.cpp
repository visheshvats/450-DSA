// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class da
{
    public:

    int start;
    int end;
    int index;

};
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.

    bool com(da a, da b)
    {
        if(a.end())

    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<da> tt;
        

        for(int i=0;i<n;i++)
        {
            da t;
            t.start=start[i]; 
            t.end=end[i]; 
            t.index=i+1; 
            tt.push_back(t);

        }

        sort(tt.begin(),tt.end(),com)
        {

        }



    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends