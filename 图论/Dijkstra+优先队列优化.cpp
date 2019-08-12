#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n, m, S, tot,head[20000];
bool visit[20000];
long long dis[20000];
struct cmp
{
	bool operator()(int a, int b)
	{
		return dis[a] > dis[b];
	}
};
priority_queue<int, vector<int>, cmp> Q;//越小优先级越高
struct node
{
	int v, l, next;
}edge[500010];
void add(int x, int y, int z)
{
	tot++;
	edge[tot].next = head[x];
	head[x] = tot;
	edge[tot].v = y;
	edge[tot].l = z;
}
int main()
{
	scanf("%d%d%d", &n, &m, &S);
	tot = 0;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (x == y) continue;
		add(x, y, z);
	}
	for (int i = 1; i <= n; i++)
	{
		visit[i] = false;
		dis[i] = 2147483647;
	}
	Q.push(S);
	dis[S] = 0;
	while (!Q.empty())
	{
		int u = Q.top();
		Q.pop();
		if (visit[u]) continue;
		visit[u] = true;
		for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].v;
			if (!visit[v] && dis[v] > dis[u] + (long long)edge[i].l)
			{
				dis[v] = dis[u] + edge[i].l;
				Q.push(v);
			}
		}
	}
	for (int i = 1; i <= n - 1; i++) printf("%lld ", dis[i]);
	printf("%lld\n", dis[n]);
	return 0;
}