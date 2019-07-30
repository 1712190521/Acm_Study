typedef long long ll;
int n, m,c[50010],allb;
struct node
{
	ll l, r,cnt;
	int q,block;
}que[50010];
ll ans[50010];
ll nl = 0, nr = -1, ncnt = 0;
bool cmp_1(node a, node b)
{
	return a.block < b.block || a.block == b.block && a.r < b.r;
}
bool cmp_2(node a, node b)
{
	return a.q < b.q;
}
void update(ll l, ll r)
{
	while (l < nl)
	{
		ncnt += ans[c[nl-1]]++;
		nl--;
	}
	while (r > nr)
	{
		ncnt += ans[c[nr+1]]++;
		nr++;
	}
	while (l > nl)
	{
		ncnt -= --ans[c[nl]];
		nl++;
	}
	while (r < nr)
	{
		ncnt -= --ans[c[nr]];
		nr--;
	}
}
long long int gcd(long long int x, long long int y)
{
	if (!y)
		return x;
	else
		return gcd(y, x % y);
}
int main()
{
	scanf("%d%d", &n, &m);
	allb = ceil(sqrt(n));
	for (int i = 1;i <= n;i++)
		scanf("%d", &c[i]);
	for (int i = 0;i < m;i++)
	{
		scanf("%lld%lld", &que[i].l, &que[i].r);
		que[i].q = i;
		que[i].block = que[i].l / allb;
	}
	sort(que, que + m, cmp_1);
	ans[0] = 1;
	nl = 0, nr = 0, ncnt = 0;
	for (int i = 0;i < m;i++)
	{
		update(que[i].l, que[i].r);
		que[i].cnt = ncnt;
	}
	sort(que, que + m, cmp_2);
	for (int i = 0;i < m;i++)
	{
		if (que[i].cnt == 0)
			printf("0/1\n");
		else
		{
			ll g,s,x,d = (que[i].r - que[i].l + 1) * (que[i].r - que[i].l) / 2;
			g = gcd(que[i].cnt, d);
			s = que[i].cnt / g;
			x = d / g;
			printf("%lld/%lld\n", s, x);
		}
	}
}