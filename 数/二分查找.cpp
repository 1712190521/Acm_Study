int main()
{
	int R = n, L = 1, p, a[100];
	cin >> p;
	while (R >= L)
	{
		int mid = (R + L) / 2;
		if (a[mid] == p)
		{
			L = R = mid;
			break;
		}
		else if (a[mid] > p)
			R = mid - 1;
		else
			L = mid + 1;
	}
}