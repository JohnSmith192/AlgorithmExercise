#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;
int n, m, x;
int a[100005];
int b[100005];
int main()
{
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	int ansi = -1;
	int ansj = -1;
	for (int i = 0, j = m - 1; i < n; i++)
	{
		while (j >= 0 && a[i] + b[j] > x)
		{
			j--;
		}
		if (a[i] + b[j] == x)
		{
			ansi = i;
			ansj = j;
		}
	}
	printf("%d %d", ansi, ansj);
	return 0;
}