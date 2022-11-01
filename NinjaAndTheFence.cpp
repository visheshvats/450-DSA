#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int add(int a, int b)
{
    return (a % mod + b % mod) % mod;
}
int mul(int a, int b)
{
    return (a % mod *1ll* b % mod) % mod;
}

int solve(int n, int k)
{
    // bc
    if (n == 1)
        return k;
    if (n == 2)
        return mul(k, k);

    // rc
    int ans = add(mul(solve(n - 2, k), (k - 1)), mul(solve(n - 1, k), (k - 1)));

    return ans;
}

int solveMem(int n, int k, vector<int> &dp)
{
    // bc
    if (n == 1)
        return k;
    if (n == 2)
        return mul(k, k);

    // rc
    if (dp[n] != -1)
        return dp[n];
    dp[n] = add(mul(solveMem(n - 2, k, dp), (k - 1)), mul(solveMem(n - 1, k, dp), (k - 1)));

    return dp[n];
}

int numberOfWays(int n, int k)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    int ans = solveMem(n, k, dp);

    return ans;
}
