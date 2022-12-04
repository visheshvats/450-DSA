#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        vector<int> a = skill;

        sort(a.begin(),a.end());

        int n  = a.size();
        int t = a[0]+a[n-1];
        long long ans =0;

        for(int i=0;i<n/2;i++)
        {
            if(t!=(a[i]+a[n-i-1]))
            {
                return -1;
            }

            ans += a[i]*a[n-i-1];
        }

        return ans;
        
    }
};