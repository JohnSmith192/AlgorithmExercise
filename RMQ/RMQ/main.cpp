#include <iostream>
using namespace std;
int m, n;
int a[100005];
int dp[100005][20];
int main()
{
	memset(dp, 0x3f, sizeof(dp));
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
		dp[i][0] = a[i];
	}
	for (int j = 1; (1 << j) <= m; j++)
	{
		for (int i = 1; i + (1 << j) - 1 <= m; i++)
		{
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
		}
	}
	while (n--)
	{
		int l, r;
		cin >> l >> r;
		int k = log(r - l + 1) / log(2);
		cout << min(dp[l][k], dp[r - (1 << k) + 1][k]) << " ";
	}
	return 0;
}