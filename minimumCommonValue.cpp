#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& a, vector<int>& b) {
        int i=0;
        int j=0;
        int ans =-1;
        while(i<a.size()&&j<b.size())
        {
            if(a[i]==b[j])
            {
                ans= a[i];
                break;
            }
            else if(a[i]>b[j])
                j++;
            else
                i++;
        }
        return ans;
        
    }
};