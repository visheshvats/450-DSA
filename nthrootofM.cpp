#include<bits/stdc++.h>
using namespace std;

double multiply(double n, double a)
{
    double ans =1;
    for(int i=1;i<=n;i++)
    {
        ans*=a;
    }
    return ans;

}

int NthRoot(int n, int m) {
  double low =1;
  double high =m;
  double eps =1e-6;
  double ans =-1;

  while((high-low)>eps)
  {
    double mid=low+(high-low)/2.0;
    double x = multiply(n, mid);
    if(x>m)
    {
     high=mid;
    }
    else
    {
        low=mid;
    }
    
  }

  return low;
}