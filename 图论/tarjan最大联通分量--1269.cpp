#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<iomanip>
#include<vector>
const int N = 100005;
using namespace std;
#define mem0(x)  memset(x,0,sizeof(x))
struct node {
	int v, next;
}edge[N];
int DFN[N], LOW[N];	int n, m;
int stack[N], heads[N], visit[N], cnt, tot, index, sum = 0,flag=0;
void add(int x, int y)
{
	edge[++cnt].next = heads[x];
	edge[cnt].v = y;
	heads[x] = cnt;
	return;
}
void tarjan(int x)//代表第几个点在处理。递归的是点。
{
	DFN[x] = LOW[x] = ++tot;// 新进点的初始化。
	stack[++index] = x;//进站
	visit[x] = 1;//表示在栈里
	for (int i = heads[x]; i!=-1; i = edge[i].next)
	{
		if (!DFN[edge[i].v]) {//如果没访问过
			tarjan(edge[i].v);//往下进行延伸，开始递归
			LOW[x] = min(LOW[x], LOW[edge[i].v]);//递归出来，比较谁是谁的儿子／父亲，就是树的对应关系，涉及到强连通分量子树最小根的事情。
		}
		else if (visit[edge[i].v]) {  //如果访问过，并且还在栈里。
			LOW[x] = min(LOW[x], DFN[edge[i].v]);//比较谁是谁的儿子／父亲。就是链接对应关系
		}
	}
	if (LOW[x] == DFN[x]) //发现是整个强连通分量子树里的最小根。
	{
		flag++;
		do {
			visit[stack[index]] = 0;
			index--;
		} while (x != stack[index + 1]);//出栈，并且输出。
	}
	return;
}
void init()
{
	sum = cnt = 0; index = tot = 0; flag = 0;
	memset(heads, -1, sizeof(heads));
	mem0(edge); mem0(visit); mem0(LOW); mem0(DFN); mem0(stack);
}
int main()
{
	while (scanf("%d%d", &n, &m) && (n||m)) {
		init();
		for (int i = 1; i <= m; i++){
			int x, y; 
			scanf("%d%d", &x, &y);
			add(x, y);
		}
		for (int i = 1; i <= n; i++)
			if (!DFN[i])  tarjan(i);//当这个点没有访问过，就从此点开始。防止图没走完
		if (flag ==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}