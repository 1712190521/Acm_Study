long long quickpow(long long a, long long b) {
	if (b < 0) return 0;
	long long ret = 1;
	a %= mod;
	while (b) {
		if (b & 1) ret = (ret * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ret;
}
long long inv(long long a) {
	return quickpow(a, mod - 2);
}