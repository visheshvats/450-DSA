#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int add(int a, int b)
{
    return ((a%MOD)+(b%MOD))%MOD;
}
int mul(int a, int b)
{
    return ((a%MOD)*1ll*(b%MOD))%MOD;
}

int solve(int n)
{
    //bc

    if(n==1)
        return 0;
    if(n==2)
        return 1;

    //RC

    int ans = mul(n-1,add(solve(n-1), solve(n-2)));

    return ans;
}


long long int countDerangements(int n) {
    // Write your code here.
    
    int ans = solve(n);

    return ans;
    
    
}