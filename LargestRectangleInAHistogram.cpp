#include<bits/stdc++.h>
using namespace std;




class Solution {

    private:

    vector<int> smallNext(vector<int> heights, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--)
        {
            int t = heights[i];
            while(s.top()!=-1&&heights[s.top()]>=t)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> smallPext(vector<int> heights, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0;i<n;i++)
        {
            int t = heights[i];
            while(s.top()!=-1&&heights[s.top()]>=t)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;

    }


public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        vector<int> next(n);
        next = smallNext(heights,n);
        vector<int> prev(n);
        prev = smallPext(heights,n);

        int maxx=INT_MIN;

        for(int i=0;i<n;i++)
        {
            int t = heights[i];
            if(next[i]==-1)
            {
                next[i]=n;
                
            }
            int w = next[i]-prev[i]-1;

            int newarea = t*w;

            maxx = max(maxx, newarea);
        }


        return maxx;
        
    }
};