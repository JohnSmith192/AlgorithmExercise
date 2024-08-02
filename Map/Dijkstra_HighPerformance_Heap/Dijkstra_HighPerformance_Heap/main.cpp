#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int n, m, d[1005], h[1005], to[1005], w[1005], ne[1005], idx;
bool v[1005];
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<PII>> q;
void add(int u, int v, int w1)
{
	to[idx] = v;
	w[idx] = w1;
	ne[idx] = h[u];
	h[u] = idx++;
}
void dijkstra()
{
	memset(d, 0x3f, sizeof(d));
	d[1] = 0;
	q.push({ 0, 1 });
	while (q.size())
	{
		int x = q.top().second;
		q.pop();
		if (v[x])
		{
			continue;
		}
		v[x] = 1;
		for (int i = h[x]; i != -1; i = ne[i])
		{
			int y = to[i], z = w[i];
			if (d[y] > d[x] + z)
			{
				d[y] = d[x] + z;
				q.push({ d[y], y });
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
	dijkstra();
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