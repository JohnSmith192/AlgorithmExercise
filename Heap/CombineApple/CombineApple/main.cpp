#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int n;
int res;
priority_queue<int, vector<int>, greater<int>> heap;
int main()
{
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		heap.push(x);
	}
	while (heap.size() > 1)
	{
		int a = heap.top();
		heap.pop();
		int b = heap.top();
		heap.pop();
		res += a + b;
		heap.push(a + b);
	}
	printf("%d\n", res);
	return 0;
}