#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int res=0;
        int lmax=0;
        int rmax=0;
        int l=0;
        int r=height.size()-1;

        while(l<r)
        {
            if(height[l]<=height[r])
            {
                lmax=max(lmax,height[l]);
                res=res-height[l]+lmax;
                l++;

            }
            else
            {
                rmax=max(rmax,height[r]);
                res=res+rmax-height[r];
                r--;

            }
        }


        return res;



    }
};