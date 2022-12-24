#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int primeFactors(int n)
    {
        int ans=0;

        while (n % 2 == 0)
        {
            ans+=2;
            n = n / 2;
        }

        for (int i = 3; i <= sqrt(n); i = i + 2)
        {

            while (n % i == 0)
            {
                ans+=i;
                n = n / i;
            }
        }

        if (n > 2)
            ans+=n;

        return ans;
    }

    int solve(int i)
    {
        int a = primeFactors(i);
        if(a==i)
            return a;
        else
            return solve(i);
    }

    int smallestValue(int n)
    {
        int ans = solve(n);
        return ans;

    }
};