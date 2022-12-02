#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int s = (n*(n+1))/2;
        int a = sqrt(s);
        if(a*a==s)
        {
            return a;
        }
        else
        {
            return -1;
            
        }
        
    }
};