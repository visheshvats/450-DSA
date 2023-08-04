#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin>>n;

    int ans=1;
    while(n%3!=0)
    {
        n-=2;
        ans*=2;
    }

    return ans*pow(3,n/3);  
}