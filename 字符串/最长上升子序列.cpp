int solve()
{
	fill(g, g + n, inf);
	int max_ = -1;
	for (int i = 0; i < n; i++)
	{
		int j = lower_bound(g, g + n, a[i]) - g;
		d[i] = j + 1;//d:1-i上升序列长度
		if (max_ < d[i])
			max_ = d[i];
		g[j] = a[i];
	}
	return max_;
}