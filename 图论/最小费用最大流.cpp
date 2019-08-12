#define MAXN_ 5000
#define P pair<int,int>
const int  INF = 0x3f3f3f3f;
struct edge { int to, cap, cost, rev; };
int T, k, c, n, m, flow, s, t, cap, res, cost, from, to, h[MAXN_], a[MAXN_];
std::vector<edge> G[MAXN_];
int dist[MAXN_], prevv[MAXN_], preve[MAXN_]; // 前驱节点和对应边
inline void add(int from, int to, int cap, int cost)
{
	G[from].push_back(edge{ to, cap, cost, (int)G[to].size() });
	G[to].push_back(edge{ from, 0, -cost, (int)G[from].size() - 1 });
} // 在vector 之中找到边的位置所在!
void min_cost_flow(int s, int t, int f)
{
	flow = 0, res = 0;
	memset(h, 0, sizeof(h));
	while (f > 0)
	{
		priority_queue<P, vector<P>, greater<P> > D;
		memset(dist, INF, sizeof dist);
		dist[s] = 0; D.push(P(0, s));
		while (!D.empty())
		{
			P now = D.top(); D.pop();
			if (dist[now.second] < now.first) continue;
			int v = now.second;
			for (int i = 0; i < (int)G[v].size(); ++i)
			{
				edge& e = G[v][i];
				if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
				{
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					prevv[e.to] = v;
					preve[e.to] = i;
					D.push(P(dist[e.to], e.to));
				}
			}
		}
		// 无法增广 ， 就是找到了答案了！
		if (dist[t] == INF) break;
		for (int i = 1; i <= n; ++i) h[i] += dist[i];
		int d = f;
		for (int v = t; v != s; v = prevv[v])
			d = min(d, G[prevv[v]][preve[v]].cap);
		f -= d; flow += d;
		res += d * h[t];
		for (int v = t; v != s; v = prevv[v])
		{
			edge& e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
}
int main()
{
	for (int i = 0; i < MAXN_; i++)
		G[i].clear();
	memset(preve, 0, sizeof(preve));
	memset(prevv, 0, sizeof(prevv));
	add(from,to,cap,cost);//cap:流量
	min_cost_flow(s, t, INF);
	printf("%d\n", res);

}