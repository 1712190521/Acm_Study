#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int pre[1010]; //����ȫ������
int unionsearch(int root)
{
	int son, tmp;
	son = root;
	while (root != pre[root]) //Ѱ������ing����
		root = pre[root];
	while (son != root) //·��ѹ��
	{
		tmp = pre[son];
		pre[son] = root;
		son = tmp;
	}
	return root; //���żݵ�~
}
int main()
{
	int num, road, total, i, start, end, root1, root2;
	while (scanf("%d%d", &num, &road) && num)
	{
		total = num - 1; //��num-1������
		for (i = 1; i <= num; ++i) //ÿ��·��������
			pre[i] = i;
		while (road--)
		{
			scanf("%d%d", &start, &end); //����Ҫ���
			root1 = unionsearch(start);
			root2 = unionsearch(end);
			if (root1 != root2) //���Ų�ͬ���߹ݣ�~
			{
				pre[root1] = root2;
				total--; //������һ�������ˣ�Ҫ����·������һ��
			}
		}
		printf("%d\n", total);//���¾��ƣ���ʣ��������
	}
	return 0;
}