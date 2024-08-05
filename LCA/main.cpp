#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m, s;
int to[1000005], ne[1000005], he[1000005], idx = 0;
int depth[500005];
int fa[500005][20];
queue<int> q;
void add(int u, int v)
{
	to[idx] = v;
	ne[idx] = he[u];
	he[u] = idx++;
}
void bfs(int k)
{
	memset(depth, 0x3f, sizeof(depth));
	depth[k] = 1;
	depth[0] = 0;
	q.push(k);
	while (q.size())
	{
		int i = q.front();
		q.pop();
		for (int j = he[i]; j != -1; j = ne[j])
		{
			int t = to[j];
			if (depth[t] > depth[i] + 1)
			{
				q.push(t);
				depth[t] = depth[i] + 1;
				fa[t][0] = i;
				for (int k = 1; k <= 19; k++)
				{
					fa[t][k] = fa[fa[t][k - 1]][k - 1];
				}
			}
		}
	}
}
int lca(int a, int b)
{
	if (depth[a] < depth[b])
	{
		swap(a, b);
	}
	for (int k = 19; k >= 0; k--)
	{
		if (depth[fa[a][k]] >= depth[b])
		{
			a = fa[a][k];
		}
	}
	if (a == b)
	{
		return a;
	}
	for (int k = 19; k >= 0; k--)
	{
		if (fa[a][k] != fa[b][k])
		{
			a = fa[a][k];
			b = fa[b][k];
		}
	}
	return fa[a][0];
}
int main()
{
	memset(he, -1, sizeof(he));
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	bfs(s);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
	return 0;
}