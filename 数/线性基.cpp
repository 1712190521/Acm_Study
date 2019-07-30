//若干数的线性基是一组数a1,a2,...an，其中ax的最高位的1在第x位。
//通过线性基中元素xor出的数的值域与原来的数xor出数的值域相同。
long long int a[65], b[65], p[65], N, x, cnt = 0, flag = 0;
bool insert(long long val)//插入构造线性基
{
	for (int i = 60; i >= 0; i--)
		if (val&(1LL << i))
		{
			if (!a[i])
			{
				a[i] = val;
				break;
			}
			val ^= a[i];
		}
	if (val == 0)flag = 1;
	return val > 0;
}
void rebuild()//重构线性基,i位上只有ai有1
{
	for (int i = 63; i >= 0; i--)
		for (int j = i - 1; j >= 0; j--)
			if (a[i]>>j & (1LL))
				a[i] ^= a[j];
	for (int i = 0; i <= 63; i++)
		if (a[i])
			p[cnt++] = a[i];
}
long long int kthquery(long long int k)//取k小值
{
	int ret = 0;
	if (k >= (1ll << cnt))
		return -1;
	for (int i = 63; i >= 0; i--)
		if ((k>>i)&1)
			ret ^= p[i];
	return ret;
}
int main()
{
	int T, Q; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		flag = 0;
		memset(a, 0, sizeof(a)); cnt = 0;
		scanf("%lld", &N);
		for (int i = 0; i < N; i++) {
			scanf("%lld", &x);
			insert(x);
		}
		rebuild();
		scanf("%d", &Q);
		printf("Case #%d:\n", t);
		if (cnt!=N) {//线性基与原来大小不同则存在1
			for (int i = 0; i < Q; i++) {
				int y, sum = 0, flag = 0;
				scanf("%d", &y);
				if (y == 1)
					printf("0\n");
				else
					printf("%lld\n", kthquery(y-1));
			}
		}
		else {
			for (int i = 0; i < Q; i++) {
				int y, sum = 0, flag = 0;
				scanf("%d", &y);
				printf("%lld\n", kthquery(y));
			}
		}
	}
}
//方法2
void build()
{
	for (int i = 1;i <= n;i++) {
		for (int j = 62;j >= 0;j--) {
			if (!(a[i] >> j)) continue;//对线性基的这一位没有贡献           
			if (!p[j]) { p[j] = a[i]; break; }//选入线性基中                   
			a[i] ^= p[j];

		}
	}
}
int ques()
{
	for (int i = 62;i >= 0;i--)
		if ((ans ^ p[i]) > ans)
			ans = ans ^ p[i];//从线性基中得到最大值
	return ans;
}