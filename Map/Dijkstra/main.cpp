#include <iostream>
using namespace std;
int a[1005][1005], d[1005], n, m;
bool v[1005];
int main()
{
	cin >> n >> m;
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++)
	{
		a[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int vi, vj, w;
		cin >> vi >> vj >> w;
		a[vi][vj] = min(a[vi][vj], w);
		a[vj][vi] = min(a[vj][vi], w);
	}
	memset(d, 0x3f, sizeof(d));
	
	d[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = 0;
		for (int j = 1; j <= n; j++)
		{
			if (!v[j] && (x == 0 || d[j] < d[x]))
			{
				x = j;
			}
		}
		v[x] = true;
		for (int j = 1; j <= n; j++)
		{
			d[j] = min(d[j], d[x] + a[x][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0x3f3f3f3f)
		{
			cout << -1 << " ";
		}
		else
		{
			cout << d[i] << " ";
		}
	}
	return 0;
}