#include <bits/stdc++.h>
using namespace std;

 int superhero(int n,  int array1[],  int array2[])
{

    vector<long long int> arr(n, 0);
    for (long long int i = 0; i < n; i++)
    {
        arr[i] = array1[i] - array2[i];
    }

    long long int L, R;
    long long int maxSum =0;

    long long int max_so_far = INT_MIN, max_ending_here = 0,
       start =0, end = 0, s=0;
 
    for (long long int i=0; i< n; i++ )
    {
        max_ending_here += arr[i];
 
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
 
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    L=start;
    R=end;


    for(long long int i=L;i<=R;i++)
    {
        long long int t=array1[i];
        array1[i]=array2[i];
        array2[i]=t;
    }

    long long int sum1=0;
    long long int sum2=0;

    for(long long int i=0;i<n;i++)
    {
        sum1+=array1[i];
    }
    for(long long int i=0;i<n;i++)
    {
        sum2+=array2[i];
    }

    return max(sum1, sum2);

}

 int main()
{
     int n;
    cin >> n;
     int array1[n];
     int array2[n];
    for ( int i = 0; i < n; i++)
    {
        cin >> array1[i];
    }
    for ( int i = 0; i < n; i++)
    {
        cin >> array2[i];
    }
    cout << superhero(n, array1, array2);
}