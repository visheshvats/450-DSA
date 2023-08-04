#include <bits/stdc++.h> 
using namespace std;

int findMaxFruits(string &str, int n) {
    // Write your code here
    unordered_map<char,int> a;
    int l=0;
    int r=0;
    int maxi=0;
    for(r=0;r<n;r++)
    {
        if(a.find(str[r])==a.end()&&a.size()<2)
        {
            a[str[r]]++;
            maxi=max(maxi,r-l+1);
        }
        else if(a.find(str[r])!=a.end()&&a.size()<=2)
        {
            a[str[r]]++;
            maxi=max(maxi,r-l+1);
        }
        else if(a.find(str[r])==a.end()&&a.size()>=2)
        {
            while(a.size()>=2)
            {
                a[str[l]]--;
                if(a[str[l]]==0)
                {
                    a.erase(str[l]);
                }
                l++;
            }
            a[str[r]]++;
            maxi=max(maxi,r-l+1);
        }
    }

    return maxi;
}