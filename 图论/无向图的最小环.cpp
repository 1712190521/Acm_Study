#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int INF = 0x3f3f3f;
int N, M;
int map[110][110], dis[110][110];
int ans;
void floyd()
{
	ans = INF;
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i < k; i++)
			for (int j = i + 1; j < k; j++)
			{
				ans = min(ans, dis[i][j] + map[j][k] + map[k][i]);
			}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
	}
}
void init()
{
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			dis[i][j] = map[i][j] = INF;
	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (z < map[x][y])
			dis[x][y] = dis[y][x] = map[x][y] = map[y][x] = z;
	}
}
int main()
{
	while (cin >> N >> M)
	{
		init();
		floyd();
		if (ans == INF)
			cout << "It's impossible." << endl;
		else
			cout << ans << endl;
	}
}