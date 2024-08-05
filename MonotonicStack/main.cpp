#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
using namespace std;
int n;
stack<int> stk;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		while (!stk.empty() && stk.top() >= t)
		{
			stk.pop();
		}
		if (stk.empty())
		{
			printf("%d ", -1);
		}
		else
		{
			printf("%d ", stk.top());
		}
		stk.push(t);
	}
	return 0;
}