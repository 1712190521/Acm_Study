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
void tarjan(int x)//����ڼ������ڴ����ݹ���ǵ㡣
{
	DFN[x] = LOW[x] = ++tot;// �½���ĳ�ʼ����
	stack[++index] = x;//��վ
	visit[x] = 1;//��ʾ��ջ��
	for (int i = heads[x]; i!=-1; i = edge[i].next)
	{
		if (!DFN[edge[i].v]) {//���û���ʹ�
			tarjan(edge[i].v);//���½������죬��ʼ�ݹ�
			LOW[x] = min(LOW[x], LOW[edge[i].v]);//�ݹ�������Ƚ�˭��˭�Ķ��ӣ����ף��������Ķ�Ӧ��ϵ���漰��ǿ��ͨ����������С�������顣
		}
		else if (visit[edge[i].v]) {  //������ʹ������һ���ջ�
			LOW[x] = min(LOW[x], DFN[edge[i].v]);//�Ƚ�˭��˭�Ķ��ӣ����ס��������Ӷ�Ӧ��ϵ
		}
	}
	if (LOW[x] == DFN[x]) //����������ǿ��ͨ�������������С����
	{
		flag++;
		do {
			visit[stack[index]] = 0;
			index--;
		} while (x != stack[index + 1]);//��ջ�����������
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
			if (!DFN[i])  tarjan(i);//�������û�з��ʹ����ʹӴ˵㿪ʼ����ֹͼû����
		if (flag ==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}