typedef long long ll;
#define N 100010
int A[N];
struct node {
	int sum, lazy;
}tree[N << 2];
ll mod = 1e9 + 7;
void pushup(int now)//更新节点
{
	tree[now].sum = tree[now << 1].sum + tree[now << 1 | 1].sum;
	tree[now].sum %= mod;
}
void create(int l, int r, int now)//造树
{
	if (l == r) {
		tree[now].lazy = tree[now].sum = 0;
		return;
	}
	int x = (l + r) >> 1;
	create(l, x, now << 1);
	create(x + 1, r, now << 1 | 1);
}
void pushdown(int l, int r, int now)//下推标记 l,r为左右节点数
{
	if (tree[now].lazy) {
		tree[now << 1].lazy += tree[now].lazy;
		tree[now << 1].lazy %= mod;
		tree[now << 1 | 1].lazy += tree[now].lazy;
		tree[now << 1 | 1].lazy %= mod;
		tree[now << 1].sum += tree[now].lazy * l;
		tree[now << 1].sum %= mod;
		tree[now << 1 | 1].sum += tree[now].lazy * r;
		tree[now << 1 | 1].sum %= mod;
		tree[now].lazy = 0;
	}
}
void modify(int L, int R, int l, int r, int now, int value)//区间修改
{
	if (l >= L && r <= R) {
		tree[now].sum += value * (r - l + 1);
		tree[now].sum %= mod;
		tree[now].lazy += value;
		tree[now].lazy %= mod;
		return;
	}
	int m = (l + r) >> 1;
	pushdown(m - l + 1, r - m, now);
	if (L <= m)modify(L, R, l, m, now << 1, value);
	if (R > m)modify(L, R, m + 1, r, now << 1 | 1, value);
	pushup(now);
}
int query(int L, int R, int l, int r, int now)//求和
{
	if (L <= l && R >= r)
		return tree[now].sum % mod;
	int m = (l + r) >> 1;
	pushdown(m - l + 1, r - m, now);
	int ans = 0;
	if (m >= L) ans += query(L, R, l, m, now << 1);
	if (m < R)ans += query(L, R, m + 1, r, now << 1 | 1);
	return ans % mod;
}
int main()
{
	int n;
	while (scanf("%d", &n) && n) {
		create(1, n, 1);
		for (int i = 0; i < n; i++) {
			int m1, n1;
			scanf("%d%d", &m1, &n1);
			modify(m1, n1, 1, n, 1, 1);
		}
		printf("%d", query(1, 1, 1, n, 1));
		for (int i = 2; i <= n; i++) {
			printf(" %d", query(i, i, 1, n, 1));
		}
		puts("");
		create(1, n, 1);//循环时还原树状数组
	}
	return 0;
}