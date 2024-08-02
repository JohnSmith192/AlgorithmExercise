#include <iostream>
using namespace std;
int f[202][202];
char s1[202], s2[202];
int m, n;
int main()
{
	cin >> s1 >> s2;
	m = strlen(s1);
	n = strlen(s2);
	for (int i = 1; i <= m; i++)
	{
		f[i][0] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		f[0][i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				f[i][j] = f[i - 1][j - 1];
			}
			else
			{
				f[i][j] = min(min(f[i - 1][j - 1], f[i - 1][j]), f[i][j - 1]) + 1;
			}
		}
	}
	cout << f[m][n] << endl;
	return 0;
}