#include<bits/stdc++.h>

using namespace std;

int removeBulbs(vector<int> &a) {
    // Write your code here.

    int l,r;
    l=-1;
    r=-1;

    for(int i=0;i<a.size();i++)
    {
        if(a[i]==1)
        {
            l=i;
            break;
        }
    }
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i]==1)
        {
            r=i;
            break;
        }
    }


    if(l==-1)
        return 0;
    int ans=0;
    for(int i=l+1;i<r;i++)
    {
        if(a[i]==0)
            ans++;
    }

    return ans;
}