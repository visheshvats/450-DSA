// C++ Program to count all subarrays having
// XOR of elements as given value m with
// O(n) time complexity.
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

// Returns count of subarrays of arr with XOR
// value equals to m
long long subarrayXor(int arr[], int n, int m)
{
    ll res = 0;

    unordered_map<int, int> mp;
    vector<int> xorsum(n, 0);
    xorsum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        xorsum[i] = xorsum[i - 1] ^ arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int tmp = xorsum[i] ^ m;

        res = res + ((ll)mp[tmp]);
        if (xorsum[i] == m)
        {
            res++;
        }

        mp[xorsum[i]]++;
    }

    return res;
}

// Driver program to test above function
int main()
{
    int arr[] = {4, 2, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 6;

    cout << "Number of subarrays having given XOR is "
         << subarrayXor(arr, n, m);
    return 0;
}
