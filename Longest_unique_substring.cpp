#include<bits/stdc++.h>

using namespace std;

int uniqueSubstrings(string input)
{
    //Write your code here
    int mas=0;
    int l=0;
    int r=0;
    vector <int>mpp(256,-1);
    int n= input.size();

    while(r<n)
    {
        if(mpp[input[r]]!=-1)
            l=max(l,mpp[input[r]]+1);

        mpp[input[r]]=r;

        mas=max(mas,r-l+1);
        r++;

    }

    return mas;
    
    
    
    
}