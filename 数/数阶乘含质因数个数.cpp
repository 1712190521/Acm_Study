/*
m!=1*2*3*����*(m-2)*(m-1)*m
���Ա�ʾ�����к�n�����йصĳ˻��ٳ���������nû�й�ϵ��
=(n*2n*3n*......*kn)*ohter other�ǲ���n���ӵ����ĳ˻���Ϊkn<=m ��k�϶������ֵ����k=m/n
=n^k*(1*2*......*k)*other
=n^k*k!*other
*/
ll solve(ll n, ll p)//��n!��p������pΪ������
{
	ll ans = 0;
	while (n)
	{
		n /= p;
		ans += n;
	}
	return ans;
}