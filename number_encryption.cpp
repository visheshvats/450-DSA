#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string a, b;
    cin >> a >> b;

    int t = 0;

    for (int i = 0; i < b.size(); i++)
    {
        char day = b[i];

        switch (day)
        {
        case 'D':
            int tuy = a[t];
            tuy--;
            a.replace(t, 1, to_string(tuy));
            break;
        case 'L':
            t--;
            break;
        case 'R':
            t++;
            break;
        case 'S':
            i++;
            int e = b[i];
            int ee = a[t];
            a.replace(t,1,to_string(e));
            a.replace(e,1,to_string(ee));
            
            break;
        case 'T':

            int tuy = a[t];
            tuy++;
            
            a.replace(t, 1, to_string(tuy));
            break;
        
        
        }
    }

    cout << a << endl;

    return 0;
}

