#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dsum(int n)
    {
        int m;
        int sum =0;
        while (n > 0)
        {
            m = n % 10;
            sum = sum + m;
            n = n / 10;
        }
        return sum;
    }
    int differenceOfSum(vector<int> &nums)
    {
        int elesum = 0;
        int digisum = 0;
        for (auto it : nums)
        {
            elesum += it;
            digisum+=dsum(it);
        }
        return abs(elesum-digisum);
    }
};