//在n种物品中选取若干件放在空间为v的背包里，每种物品的体积为c1，c2，…，cn，
//与之相对应的价值为w1,w2，…，wn.求解怎么装物品可使背包里物品总价值最大
//01背包——每种物品只能选0件或者1件
#define M 8 //背包容量
#define N 6	// 物品个数
#define max(x,y) x > y ? x : y	//定义比大小的宏
int V[N + 1][M + 1] = {0};	//定义一个二维数组存储所有状态的背包对应价值，因为V[0][]和V[][0]都必须初始为0所以下标0不能作为有效数据，要多设置一个下标数据
int weight[N+1] ={0,1,2,3,4,5,6};	//同上weight[]和value[]的0下标位都初始化为0，不放数据，这个不是必须的，但是方便理解
int value[N+1] = {0,2,3,4,5,6,7};
void package01()
{
	for(int i = 1; i <= N; i++)		//i对应第i个物品，i的循环放外面，这个是关键点，一行一行的写入数据。因为V[i][]对应数据是由V[i-1][]决定的，因此上一行数据的完整才能保证下一行数据完整
	{
		for(int j = 1; j <= M; j++)	//j对应当前背包能承受重量为j
		{
			if(j >= weight[i])	
			{
				V[i][j] = max(V[i - 1][j], V[i - 1][j - weight[i]] + value[i]);
			}
			else
			{
				V[i][j] = V[i - 1][j];
			}
		}
	}
}
void package01EX()//优化为只用一位数组
{
	for(int i = 1; i <= N; i++)
	{
		for (int j = M; j >= 1; j--)
		{
			if (j >= weight[i])
			{
				V[j] = max(V[j], V[j - weight[i]] + value[i]);
			}
		}
	}
}
