
#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n) {
        
        int count = (int) n/log(n);

        return count;
        
        
    }

int main()
{
    int n;
    cin>>n;
    int count =1;
    while(n>1)
    {
        int t=countPrimes(n);
        n=n-t;
        count++;
    }

    cout<<count<<endl;


    return 0;

    
}

