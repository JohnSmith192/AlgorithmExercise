#include <iostream>
#include <queue>
using namespace std;
int n, m, d[1005];
bool v[1005];
int h[1005], to[10005], w[10005], ne[10005], idx;
void add(int x, int y, int z)
{
	to[idx] = y;
	w[idx] = z;
	ne[idx] = h[x];
	h[x] = idx++;
}
void spfa()
{
	memset(d, 0x3f, sizeof(d));
	queue<int> q;
	d[1] = 0;
	q.push(1);
	v[1] = true;
	while (q.size())
	{
		int x = q.front();
		q.pop();
		v[x] = 0;
		for (int i = h[x]; i != -1; i = ne[i])
		{
			int y = to[i], z = w[i];
			if (d[y] > d[x] + z)
			{
				d[y] = d[x] + z;
				if (!v[y])
				{
					q.push(y);
					v[y] = 1;
				}
			}
		}
	}
}
int main()
{
	int x, y, z;
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}
	spfa();
	for (int i = 1; i <= n; i++)
	{
		cout << d[i] << " ";
	}
	return 0;
}