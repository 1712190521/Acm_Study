ull res[maxn][maxn], tmp[maxn][maxn],mat[maxn][maxn];
void mul(ull a[][maxn], ull b[][maxn], ll l)//l为矩阵大小
{
	for (int i = 0;i < l;i++)
		for (int j = 0;j < l;j++)
		{
			tmp[i][j] = 0;
			for (int k = 0;k < l;k++)
				tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]);
		}
	for (int i = 0;i < l;i++)
		for (int j = 0;j < l;j++)
			a[i][j] = tmp[i][j];
}
void pow(ll k, ll l)//求mat^k,res为结果
{
	memset(res, 0, sizeof(res));
	for (int i = 0;i < l;i++)
		res[i][i] = 1;
	while (k)
	{
		if (k & 1) mul(res, mat, l);
		mul(mat, mat, l);
		k /= 2;
	}
}
#define mo 1000000007
long long m[3];
typedef long long ll;
long long a, b, c, d, p;
long long  n;
long long f1, f2;
struct Matrix
{
	long long  m[3][3];
	Matrix() {
		memset(m, 0, sizeof(m));
	}
	Matrix operator*(Matrix &tmp) {
		Matrix ans;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 3; ++k) {
					ans.m[i][j] = (ans.m[i][j] + m[i][k] * tmp.m[k][j]);
				}
				ans.m[i][j] %= mo;
			}
		}
		return ans;
	}
}aa, bb;
Matrix fastm(Matrix a, int n)
{
	Matrix res;
	memset(res.m, 0, sizeof(res.m));
	res.m[0][0] = res.m[1][1] = res.m[2][2] = 1;
	while (n)
	{
		if (n & 1)
			res = res * a;
		n >>= 1;
		a = a * a;
	}
	return res;
}