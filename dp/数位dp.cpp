//求二进制0数量>1的个数
int a[105], cnt, d[105][105][105];
int dp(int cnt, int n1, int n0, bool flag, bool qd0)
{//flag-前面几位是否为上限  qd0-前面是否是前导0
	if (cnt == -1)
	{
		return n0 >= n1;
	}
	int len = flag ? a[cnt] : 1;
	int ans = 0;
	if (!flag && !qd0 && d[cnt][n1][n0] != -1)return d[cnt][n1][n0];
	for (int i = 0;i <= len;i++)
	{
		ans += dp(cnt - 1, n1 + (i == 1), n0 + (!qd0 && i == 0), flag && (i == len), qd0 && (i == 0));
	}
	if (!flag && !qd0)d[cnt][n1][n0] = ans;
	return ans;
}
int cal(ll x)
{
	cnt = 0;
	while (x)
	{
		a[cnt++] = x & 1;
		x >>= 1;
	}
	return dp(cnt - 1, 0, 0, 1, 1);
}
int main()
{
	memset(d, -1, sizeof(d));
	ll a, b;
	cin >> a >> b;
	cout << cal(b) - cal(a - 1) << endl;
}