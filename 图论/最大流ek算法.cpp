#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
const int maxn = 300;
const int inf = 1e9;
int N, M;
int Map[maxn][maxn];
int Maxflow;
int Flow[maxn];//流入节点i的流
bool visit[maxn];
int father[maxn];//用于路径回溯
void init()
{
	memset(Map, 0, sizeof(Map));
	Maxflow = 0;
}
void solve(int s, int e)
{

	queue<int> Q;
	while (1)//寻找增广路径，直到找不到增广路径为止推出循环
	{
		memset(visit, false, sizeof(visit));
		while (!Q.empty()) Q.pop();
		memset(Flow, 0, sizeof(Flow));
		Flow[s] = inf;//流入源点的流无穷大
		Q.push(s);
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			visit[u] = true;
			for (int i = s; i <= e; i++)
			{
				if (!visit[i] && Map[u][i] > 0)
				{
					visit[i] = true;
					Q.push(i);
					Flow[i] = min(Flow[u], Map[u][i]);//找出增广路径上的一个最小能满足所有的流
					father[i] = u;//用于回溯
				}
			}
			if (Flow[e] > 0)//找到了汇点,准备反向回溯
			{
				for (int i = e; i != 1; i = father[i])
				{
					Map[father[i]][i] -= Flow[e];
					Map[i][father[i]] += Flow[e];
				}
				break;
			}
		}
		if (Flow[e] == 0) break;//找不到增广路径了，跳出循环
		Maxflow += Flow[e];
	}
}
int main()
{
	while (~scanf("%d%d", &N, &M))
	{
		init();
		int u, v, w;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			Map[u][v] += w;
		}
		solve(1, M);
		printf("%d\n", Maxflow);
	}
	return 0;
}