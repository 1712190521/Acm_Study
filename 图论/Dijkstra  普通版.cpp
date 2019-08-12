#include<cstdio>
#include<cstring>
const int N = 105, INF = 9999999;
int d[N], w[N][N], vis[N], n, m;

void Dijkstra(int src) {
	for (int i = 1; i <= n; ++i)
		d[i] = INF;
	d[src] = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; ++i) {
		int u = -1;
		for (int j = 1; j <= n; ++j)if (!vis[j]) {
			if (u == -1 || d[j]<d[u]) u = j;
		}
		vis[u] = 1;
		for (int j = 1; j <= n; ++j)if (!vis[j]) {
			int tmp = d[u] + w[u][j];
			if (tmp<d[j]) d[j] = tmp;
		}
	}
}
int main() {
	int a, b, c;
	while (scanf("%d%d", &n, &m) && n + m) {
		for (int i = 1; i <= n; ++i) {
			w[i][i] = INF;
			for (int j = i + 1; j <= n; ++j)
				w[i][j] = w[j][i] = INF;
		}
		for (int i = 0; i<m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			w[a][b] = w[b][a] = c;
		}
		Dijkstra(1);
		printf("%d\n", d[n]);
	}
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include<string.h>
const int N = 1002, MAX= 0x3f3f3f3f;
int a[N][N], n, t, s, d;
void init()
{
	int x, y, z, i, j;
	memset(a, MAX, sizeof(a));
	n = 0;
	for (i = 1; i <= t; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (z<a[x][y]) a[y][x] = a[x][y] = z;
		if (x>n) n = x;
		if (y>n) n = y;
	}
	n++;
	for (i = 1; i <= s; i++) { scanf("%d", &x); a[0][x] = 0; }
	for (i = 1; i <= d; i++) { scanf("%d", &x); a[x][n] = 0; }
}
void dijkstra()
{
	int min, p, v[N] = { 0 }, i, j;
	for (j = 1; j <= n; j++)
	{
		min = MAX;p=0;
		for (i = 1; i <= n; i++)
			if (a[0][i]<min && !v[i])
			{
				min = a[0][i];
				p = i;
			}
		v[p] = 1;
		for (i = 1; i <= n; i++)
			if (a[0][p] + a[p][i]<a[0][i])
				a[0][i] = a[0][p] + a[p][i];
	}
}
int main()
{
	while (scanf("%d%d%d", &t, &s, &d) != EOF)
	{
		init();
		dijkstra();
		printf("%d\n", a[0][n]);
	}
	return 0;
}