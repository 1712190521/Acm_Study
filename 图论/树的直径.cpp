#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
#define N 200200
struct node { ll x, y, z, next; }edge[2 * N];
ll d[N], vis[N], h[N], pos, num = 0;
ll max1 = 0, sum = 0;

void insert(ll x, ll y, ll z) {
	edge[++num].x = x; edge[num].y = y; edge[num].z = z; edge[num].next = h[x]; h[x] = num;
	edge[++num].x = y; edge[num].y = x; edge[num].z = z; edge[num].next = h[y]; h[y] = num;
}

void dfs(ll x) {
	for (ll i = h[x]; i; i = edge[i].next) {
		ll y = edge[i].y;
		if (vis[y]) continue;
		d[y] = d[x] + edge[i].z; vis[y] = 1; dfs(y);
		if (d[y] > max1) max1 = d[y], pos = y;
	}
}

void getd()
{
	memset(d, 0, sizeof(d)); memset(vis, 0, sizeof(vis)); vis[1] = 1; max1 = 0; dfs(1);
	memset(d, 0, sizeof(d)); memset(vis, 0, sizeof(vis)); vis[pos] = 1; max1 = 0; dfs(pos);
	printf("%lld\n", max1);
}

int main()
{
	ll n, x, y, z;
	sum = 0;
	scanf("%d", &n);
	for (ll i = 0; i < n - 1; i++)
	{
		scanf("%lld%lld%lld", &x, &y, &z);
		insert(x, y, z);
	}
	getd();
	return 0;
}