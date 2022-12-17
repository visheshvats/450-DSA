#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> number(n);
        for(int i=1;i<=n;i++)
        {
            fact=fact*i;
            number[i-1]=i;

        }
        string ans;
        k=k-1;
        fact=fact/n;


        while(true)
        {
            ans=ans+(to_string(number[k/fact]));
            number.erase(number.begin()+k/fact);
            if(number.size()==0)
                break;
            k=k%fact;
            fact=fact/number.size();

        }

        return ans;
        
    }
};