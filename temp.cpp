// A simple C++ program to generate all rotations
// of a given string
#include <bits/stdc++.h>
using namespace std;

void rotateEasy(string str)
{
    unordered_map<string, int> aa;
    int len = str.length();

    char temp[len];
    for (int i = 0; i < len; i++)
    {
        int j = i;
        int k = 0;

        while (str[j] != '\0')
        {
            temp[k] = str[j];
            k++;
            j++;
        }

        j = 0;
        while (j < i)
        {
            temp[k] = str[j];
            j++;
            k++;
        }

        aa[temp]++;
        int n = strlen(temp);

        for (int i = 0; i < n / 2; i++)
            swap(temp[i], temp[n - i - 1]);

        aa[temp]++;
    }

    cout << aa.size();
}

// Driven Program
int main()
{
    string a = "aabbbbaaaabbbbaaa";
    // unordered_map<string, int> aa;
    rotateEasy(a);

    return 0;
}
