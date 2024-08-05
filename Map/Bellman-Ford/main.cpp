#include <iostream>
using namespace std;
struct Edge
{
	int u, v, w;
};
Edge edge[10010];
int n, m, k;
int dis[510];
void bf()
{
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 2 * m; j++)
		{
			Edge e = edge[j];
			dis[e.v] = min(dis[e.v], dis[e.u] + e.w);
		}
	}
}
int main()
{
	cin >> n >> m;
	k = n - 1;
	for (int i = 0; i < m; i++)
	{
		int vi, vj, vw;
		cin >> vi >> vj >> vw;
		edge[i] = { vi, vj, vw };
		edge[i + m] = { vj, vi, vw };
	}
	bf();
	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << " ";
	}
	return 0;
}