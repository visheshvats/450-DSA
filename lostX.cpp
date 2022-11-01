#include <bits/stdc++.h> 
using namespace std;

int lostX(vector<int> &a){
    // Write your code here
    int res =0;
    for(int i=0;i<a.size();i++)
    {
        res = res | a[i];
    }

    return res;
}