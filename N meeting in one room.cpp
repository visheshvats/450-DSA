// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
     bool com(tuple<int,int,int> a, tuple<int,int,int> b)
    {
        if(get<1>(a)<get<1>(b)) return true;
        else if(get<1>(a)==get<1>(b))
        {
            if(get<2>(a)<get<2>(b))
                return true;
        }

        else
            return false;


    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int count =0;
        if (n==0)
        {
            return count;

        }

        tuple<int,int,int> a;

        vector<tuple<int,int,int>> tt;
        

        for(int i=0;i<n;i++)
        {
            tuple<int,int,int> t;
            get<0>(t)=end[i]; 
            get<1>(t)=i+1; 
            get<2>(t)=start[i]; 
             
            tt.push_back(t);

        }

        sort(tt.begin(),tt.end());
        
        count++;
        int x=get<0>(tt[0]);

        for(int i=1;i<n;i++)
        {
            if(get<2>(tt[i])>x)
            {
                count++;
                x=get<0>(tt[i]);
            }
        }

        return count;



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