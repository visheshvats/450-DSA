#include <bits/stdc++.h>
using namespace std;

int summ(int n)
{
    int sum=0,m;
    while (n > 0)
    {
        m = n % 10;
        sum = sum + m;
        n = n / 10;
    }

    return sum;
}

int main(void)
{
    int a;
    int b;
    cin >> a >> b;
    double i=1;
    int res=0;

    while (!summ(a) <= b)
    {
        int tt=pow(10, i);
        int n=a % tt;
        n=tt-n;
        res=res+n;
        i++;
        a=a+n;
        




    }

    cout<<res<<endl;

    return 0;
}