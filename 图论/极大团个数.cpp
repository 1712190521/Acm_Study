#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
#define MAXN (150+5)
#define INF 0x3f3f3f3f
#define For(i, a, b) for(int i = (a); i <= (int)(b); i++)
bool G[MAXN][MAXN];
int n, m, S, all[MAXN][MAXN], some[MAXN][MAXN], none[MAXN][MAXN];
void dfs(int d, int an, int sn, int nn) {
	if (!sn && !nn)
		S++;
	if (S > 1000)
		return;
	int u = some[d][1];
	For(i, 1, sn) {
		int v = some[d][i];
		if (G[u][v])
			continue;
		int tsn = 0, tnn = 0;
		For(j, 1, an)
			all[d + 1][j] = all[d][j];
		all[d + 1][an + 1] = v;
		For(j, 1, sn)
			if (G[v][some[d][j]]) 
				some[d + 1][++tsn] = some[d][j];
		For(j, 1, nn)
			if (G[v][none[d][j]]) 
				none[d + 1][++tnn] = none[d][j];
		dfs(d + 1, an + 1, tsn, tnn);
		some[d][i] = 0; none[d][++nn] = v;
	}
}
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(G, 0, sizeof(G));
		For(i, 1, m) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u][v] = G[v][u] = true;
		}
		For(i, 1, n) some[0][i] = i;
		S = 0;
		dfs(0, 0, n, 0);
		if (S <= 1000) printf("%d\n", S);
		else printf("Too many maximal sets of friends.\n");
	}
	return 0;
}