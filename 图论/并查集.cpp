#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int pre[1010]; //里面全是掌门
int unionsearch(int root)
{
	int son, tmp;
	son = root;
	while (root != pre[root]) //寻找掌门ing……
		root = pre[root];
	while (son != root) //路径压缩
	{
		tmp = pre[son];
		pre[son] = root;
		son = tmp;
	}
	return root; //掌门驾到~
}
int main()
{
	int num, road, total, i, start, end, root1, root2;
	while (scanf("%d%d", &num, &road) && num)
	{
		total = num - 1; //共num-1个门派
		for (i = 1; i <= num; ++i) //每条路都是掌门
			pre[i] = i;
		while (road--)
		{
			scanf("%d%d", &start, &end); //他俩要结拜
			root1 = unionsearch(start);
			root2 = unionsearch(end);
			if (root1 != root2) //掌门不同？踢馆！~
			{
				pre[root1] = root2;
				total--; //门派少一个，敌人（要建的路）就少一个
			}
		}
		printf("%d\n", total);//天下局势：还剩几个门派
	}
	return 0;
}
//2
int path[100];
int rank[100];
// 初始化 n 个元素
void init(int n)
{
    for (int i=0; i<n; i++)
    {
        path[i] = i;
        rank[i] = 0;
    }
}

// 查询树的根
int find(int x)
{
    int r=x;
    while(r!=path[r])
        r=path[r];
    int i=r,j=-1;

    while(i!=j)
    {
        j=path[i];  // 在改变上级之前，用临时变量 j 记录下他的值
        path[i]=r;  // 把上级节点改为根节点
        i=j;
    }
    return r;
}

// 合并 x 和 y 所属的合集
void merge(int x, int y)
{
    fx = find(x);
    fy = find(y);
    if (fx == fy) return;
    if (rank[fx] < rank[fy])
        path[fx] = fy;
    else
    {
        path[fy] = fx;
        if (rank[fx] == rank[fy]) rank[fx] ++;
    }
}
