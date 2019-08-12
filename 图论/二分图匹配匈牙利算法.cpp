#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, nx, t[100][100], cx[100], cy[100], vis[100], n, k;
bool dfs(int u) {
	for (int v = 1; v <= m; v++)
		if (t[u][v]&&!vis[v]) {
			vis[v] = 1;
			if (cy[v] == -1 || dfs(cy[v])) {
				cx[u] = v; cy[v] = u;
				return 1;
			}
		}
	return 0;
}
int maxmatch()//匈牙利算法主函数
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (cx[i] == -1)//如果i未匹配
		{
			memset(vis,0, sizeof(vis));
			ans += dfs(i);
		}
	return ans;
}
int main()
{
	while (scanf("%d", &n) && n) {
		cin >> m >> k;
		memset(cx, -1, sizeof cx);
		memset(cy, -1, sizeof cy);
		memset(t, 0, sizeof(t));
		for (int i = 0; i < k; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			t[b][c] = 1;
		}
		printf("%d\n", maxmatch());
	}
	return 0;
}