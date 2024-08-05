#include <iostream>
#include <string.h>
using namespace std;
int n, m;
int q;
int f[20005], siz[20005];
int Find(int k);
void Union(int u, int v)
{
	int t1 = Find(u);
	int t2 = Find(v);
	if (t1 == t2)
	{
		return ;
	}
	if (siz[t1] > siz[t2])
	{
		swap(t1, t2);
	}
	f[t2] = t1;
	siz[t1] += siz[t2];
}
int Find(int k)
{
	if (f[k] == k)
	{
		return k;
	}
	return f[k] = Find(f[k]);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		siz[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}
	cin >> q;
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		if (Find(u) == Find(v))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}