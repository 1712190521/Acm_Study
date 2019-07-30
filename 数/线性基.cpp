//�����������Ի���һ����a1,a2,...an������ax�����λ��1�ڵ�xλ��
//ͨ�����Ի���Ԫ��xor��������ֵ����ԭ������xor������ֵ����ͬ��
long long int a[65], b[65], p[65], N, x, cnt = 0, flag = 0;
bool insert(long long val)//���빹�����Ի�
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
void rebuild()//�ع����Ի�,iλ��ֻ��ai��1
{
	for (int i = 63; i >= 0; i--)
		for (int j = i - 1; j >= 0; j--)
			if (a[i]>>j & (1LL))
				a[i] ^= a[j];
	for (int i = 0; i <= 63; i++)
		if (a[i])
			p[cnt++] = a[i];
}
long long int kthquery(long long int k)//ȡkСֵ
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
		if (cnt!=N) {//���Ի���ԭ����С��ͬ�����1
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
//����2
void build()
{
	for (int i = 1;i <= n;i++) {
		for (int j = 62;j >= 0;j--) {
			if (!(a[i] >> j)) continue;//�����Ի�����һλû�й���           
			if (!p[j]) { p[j] = a[i]; break; }//ѡ�����Ի���                   
			a[i] ^= p[j];

		}
	}
}
int ques()
{
	for (int i = 62;i >= 0;i--)
		if ((ans ^ p[i]) > ans)
			ans = ans ^ p[i];//�����Ի��еõ����ֵ
	return ans;
}