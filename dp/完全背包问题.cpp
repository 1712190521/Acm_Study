//完全背包问题跟01背包的区别是01背包每个物品只能选一次，总共就这几个，而完全背包问题是每个物品可以无限选，只要装得下。可以看成是有几种物品，每种都无限多个。
void packageTotal()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = M; j >= 1; j--)	//跟01背包一样，也是从右向左更新数据，因为更新时候需要上次循环左边的数据
		{
			int k = j / weight[i];	//如果能放下，要看看能放几个，然后放几个跟不放所有情况比一下看哪个价值最大
			for (int m = 0; m <= k; m++)	
			{
				if (V1[j - m * weight[i]] + m * value[i] > V1[j])
				{
					V1[j] = V1[j - m * weight[i]] + m * value[i];
				}
			}		
		}
	}
}
void packageTotal()//优化后
{
	for(int i = 1; i <= N; i++ )
	{
		for(int j = 1; j <= M; j++) //相比01背包最终优化代码，只是换了遍历方向而已
		{
			if(j >= weight[i])
			{
				V1[j] = max(V1[j], V1[j - weight[i]] + value[i]);
			}
		}
	}
}
