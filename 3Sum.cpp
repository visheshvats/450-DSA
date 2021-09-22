#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        
        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                
                int l = i + 1;
                int r = n - 1;

                while (l < r)
                {
                    if (nums[i] + nums[l] + nums[r] == 0)
                    {
                        vector<int> tt;
                        tt.push_back(nums[i]);
                        tt.push_back(nums[l]);
                        tt.push_back(nums[r]);

                        res.push_back(tt);

                        while (l < r && nums[l] == nums[l + 1])
                            l++;
                        while (l < r && nums[r] == nums[r - 1])
                            r--;

                        l++;
                        r--;
                    }

                    else if (nums[i] + nums[l] + nums[r] > 0)
                    {
                        r--;
                    }

                    else if (nums[i] + nums[l] + nums[r] < 0)
                    {
                        l++;
                    }
                }
            }
        }

        return res;
    }
};