#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n=7;
	int x[7] = {5, 6, 9, 11, 12, 16, 20};
	int l[7] = {2, 3, 1, 5, 3, 1, 1};
	int h = 0;
	h = max(x[0] + 1, x[0] + l[0]);
	int i = 0;
	for (; i < n; i++)
	{
		if (h >= x[i])
		{
			h = max(x[i] + 1, x[i] + l[i]);
		}
		else
		{
			break;
		}
	}
	for (int j = 0; j <= i; j++)
	{
		x[i] = h;
	}
	for (; i < n; i++)
	{
		x[i] += l[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << "\n";
	}

	return 0;
}