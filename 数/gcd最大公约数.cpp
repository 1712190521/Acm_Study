long long int gcd(long long int x, long long int y)
{
	if (!y)
		return x;
	else
		return gcd(y, x%y);
}
int main()
{
	long long int x, a, b;
	scanf("%lld %lld", &a, &b);
	if (a > b) {
		x = gcd(a, b);
		printf("%lld", b*(a / x));
	}
	else {
		x = gcd(b, a);
		printf("%lld", a *(b / x));
	}
	return 0;
}