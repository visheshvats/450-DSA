#include<bits/stdc++.h>
using namespace std;


vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);
    vector<int> aa(n);

    for(int i=n-1;i>=0;i--)
    {
        int c = arr[i];

        while(s.top()>=c)
        {
            s.pop();
        }

        aa[i]=s.top();
        s.push(c);
    }

    return aa;
}