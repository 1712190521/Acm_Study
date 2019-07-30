/*
m!=1*2*3*……*(m-2)*(m-1)*m
可以表示成所有和n倍数有关的乘积再乘以其他和n没有关系的
=(n*2n*3n*......*kn)*ohter other是不含n因子的数的乘积因为kn<=m 而k肯定是最大值所以k=m/n
=n^k*(1*2*......*k)*other
=n^k*k!*other
*/
ll solve(ll n, ll p)//求n!含p个数，p为质因数
{
	ll ans = 0;
	while (n)
	{
		n /= p;
		ans += n;
	}
	return ans;
}