/*
    Time Complexity: O(N*M)
    Space Complexity: O(N)

    Where 'N' is the size of the array and 'M' is the number of available candies.
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> birthdayTreat(vector < vector<int> > & v , int &m) {

    // Create an array ‘count’ of length ‘M’ and initialise it to 0.
    int count[m + 1] = {};

    int n = v.size();
    for (int i = 0; i < n; i++) {
        int l = v[i][0];
        int r = v[i][1];
        int x = v[i][2];

        // Adding ‘X’ to each position from L to R, inclusive.
        for (int j = l; j <= r; j++) {
            count[j] += x;
        }
    }

    // Create an array 'arr' to sort elements in order of decreasing frequency
    vector<pair<int, int>>arr;
    for (int i = 1; i <= m; i++) {
        arr.push_back({count[i], i});
    }

    // Sorting in decreasing order of frequency and lexicographically minimum
    auto cmp = [] (pair<int, int> const & a, pair<int, int> const & b) -> bool
    {
        if (a.first == b.first)return a.second < b.second;
        return a.first > b.first;
    };
    sort(arr.begin(), arr.end(), cmp);

    vector<int>ans(m);

    // Forming the permutation according to the sorted values.
    for (int i = 0; i < m; i++) {
        ans[arr[i].second - 1] = i + 1;
    }

    // Returning answer here.
    return ans;
}
