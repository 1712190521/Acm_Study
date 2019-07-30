ll q_mul(ll a, ll b, ll mod)
{
	ll ans = 0, res = a;
	while (b)
	{
		if (b & 1)
			ans = (ans + res) % mod;
		res = (res + res) % mod;
		b >>= 1;
	}
	return ans;
}
ll q_pow(ll a, ll b, ll mod)
{
	ll ans = 1, res = a;
	while (b)
	{
		if (b & 1)
			ans = q_mul(ans, res, mod);
		res = q_mul(res, res, mod);
		b >>= 1;
	}
	return ans;
}