#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
using namespace std;
int n;
long long ans = -1;
long long le[1000005], ri[1000005], a[1000005];
stack<int> stk;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	a[0] = -1;
	a[n + 1] = -1;
	stk.push(0);
	for (int i = 1; i <= n; i++)
	{
		while (a[stk.top()] >= a[i])
		{
			stk.pop();
		}
		le[i] = stk.top();
		stk.push(i);
	}
	while (stk.size())
	{
		stk.pop();
	}
	stk.push(n + 1);
	for (int i = n; i > 0; i--)
	{
		while (a[stk.top()] >= a[i])
		{
			stk.pop();
		}
		ri[i] = stk.top();
		stk.push(i);
	}
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, a[i] * (ri[i] - le[i] - 1));
	}
	printf("%d", ans);
	return 0;
}