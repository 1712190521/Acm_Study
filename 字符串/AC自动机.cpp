//����ܶ�����ʣ�Ȼ�����һ���ַ����������ж��ٸ�����������ַ����г��ֹ�
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 500010;
struct Trie
{
	int nxt[maxn][26], fail[maxn], end[maxn];
	//nxtΪ�ֵ���, fail�൱��kmp�е�nxt����, end�Ե��ʽ�β����� 
	int root, L;  //L�൱���ֵ����е�sz ��rootΪ���ڵ㣨����0�� 
	int newnode() //���൱��ʼ��һ���ֵ����ϵĽڵ� 
	{
		for (int i = 0;i < 26;i++) nxt[L][i] = -1;
		end[L++] = 0;
		return L - 1;
	}
	void init()
	{
		L = 0;
		root = newnode();
	}
	void insert(char buf[]) //�������ֵ������������ͬ 
	{
		int len = strlen(buf);
		int now = root;
		for (int i = 0;i < len;i++)
		{
			int x = buf[i] - 'a';
			if (nxt[now][x] == -1) nxt[now][x] = newnode();
			now = nxt[now][x];
		}
		end[now]++; //�ڵ��ʽ�β������� 
	}
	void build()  //�൱��kmp�Ĳ��� 
	{
		queue<int>que;
		fail[root] = root; //���ڵ��ʼ��Ϊ0(���䱾��)
		for (int i = 0;i < 26;i++)
		{
			if (nxt[root][i] == -1) nxt[root][i] = root;
			else //Trie���Ѿ������Ľڵ� 
			{
				int x = nxt[root][i];
				fail[x] = root;
				que.push(x);
			}
		}
		while (!que.empty())
		{
			int now = que.front();
			que.pop();
			for (int i = 0;i < 26;i++)
			{
				if (nxt[now][i] == -1) //�޺�̵� 
					nxt[now][i] = nxt[fail[now]][i];//������kmp����nxt����һ�� 
				else //������һ���ڵ� 
				{
					int x = nxt[now][i];
					fail[x] = nxt[fail[now]][i];
					//ʧ��ָ��ָ�������ڵ��ʧ��ָ�����һ����ͬ�ַ��� 
					que.push(x);
				}
			}
		}
	}
	int query(char buf[]) //�൱���ֵ����еķ��ʲ��� 
	{
		int len = strlen(buf);
		int now = root;
		int res = 0;
		for (int i = 0;i < len;i++)
			//���������ı����ƶ�,ÿ�ƶ���һ���ַ����ڵ㣩 ʱ��ͨ��ʧ��ָ�벻����Ѱģʽ�� ���ص�ΪԴͷ,�ҵ�һ���ͽ�������� 
		{
			now = nxt[now][buf[i] - 'a'];
			int tmp = now;
			while (tmp != root)
			{
				res += end[tmp];
				end[tmp] = 0;
				tmp = fail[tmp];
			}
		}
		return res; //���ص��ʸ��� 
	}
	void debug()
	{
		for (int i = 0;i < L;i++)
		{
			printf("%id=%3d,fail=%3d,end=%3d,chi=[", i, fail[i], end[i]);
			for (int j = 0;j < 26;j++) printf("%2d", nxt[i][j]);
			printf("]\n");
		}
	}
};
char buf[maxn * 2];
Trie ac;
int main()
{
	int T, n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		ac.init();
		for (int i = 0;i < n;i++)
		{
			scanf("%s", buf);
			ac.insert(buf);
		}
		ac.build();
		scanf("%s", buf);
		printf("%d\n", ac.query(buf));
	}
	return 0;
}