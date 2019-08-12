//由某个集合上的一个偏序得到该集合上的一个全序
using namespace std;
#define maxn 30005
int in[maxn];
vector<int> edge[maxn];
priority_queue<int>q;
int n, m, t;
int main()
{
	while (scanf("%d%d", &n, &m)!=EOF)
	{
		vector<int>ans;
		memset(in, 0, sizeof(in));
		if (!q.empty())q.pop();
		for (int i = 1; i <= n; i++)edge[i].clear();
		while (m--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			in[a]++;
			edge[b].push_back(a);
		}
		for (int i = 1; i <= n; i++)
			if (in[i] == 0)
				q.push(i);
		while (!q.empty())
		{
			int p = q.top();
			ans.push_back(p);
			q.pop();
			for (int i = 0; i < edge[p].size(); i++)
			{
				int x = edge[p][i];
				in[x]--;
				if (in[x] == 0)
					q.push(x);
			}
		}
		for (int i = ans.size() - 1; i >= 0; i--)
			if (i != 0)
				printf("%d ", ans[i]);
			else
				printf("%d\n", ans[i]);
	}
	return 0;
}