#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int left=0;
        int right=height.size()-1;
        int maxleft=height[left];
        int maxright=height[right];

        while(left<=right)
        {
            if(maxleft<=maxright)
            {
                if(maxleft<=height[left]) maxleft=height[left];
                res+=maxleft-height[left];
                left++;
            }
            else if(maxright>=maxleft)
            {
                if(maxright<=height[right]) maxright=height[right];
                res+=maxright-height[right];
                right++;
            }
        }

        return res;
        
    }
};