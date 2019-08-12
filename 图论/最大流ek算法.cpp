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
int Flow[maxn];//����ڵ�i����
bool visit[maxn];
int father[maxn];//����·������
void init()
{
	memset(Map, 0, sizeof(Map));
	Maxflow = 0;
}
void solve(int s, int e)
{

	queue<int> Q;
	while (1)//Ѱ������·����ֱ���Ҳ�������·��Ϊֹ�Ƴ�ѭ��
	{
		memset(visit, false, sizeof(visit));
		while (!Q.empty()) Q.pop();
		memset(Flow, 0, sizeof(Flow));
		Flow[s] = inf;//����Դ����������
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
					Flow[i] = min(Flow[u], Map[u][i]);//�ҳ�����·���ϵ�һ����С���������е���
					father[i] = u;//���ڻ���
				}
			}
			if (Flow[e] > 0)//�ҵ��˻��,׼���������
			{
				for (int i = e; i != 1; i = father[i])
				{
					Map[father[i]][i] -= Flow[e];
					Map[i][father[i]] += Flow[e];
				}
				break;
			}
		}
		if (Flow[e] == 0) break;//�Ҳ�������·���ˣ�����ѭ��
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