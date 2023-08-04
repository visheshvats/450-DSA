#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int maxx=INT_MIN;
        int n = salary.size();
        int minn=INT_MAX;
        double sum =0;
        for(double i=0;i<n;i++)
        {
            sum+=salary[i];
            maxx=max(maxx, salary[i]);
            minn=min(minn, salary[i]);
        }
        sum=sum - maxx;
        sum=sum - minn;


        return sum/(n-2);
        
    }
};