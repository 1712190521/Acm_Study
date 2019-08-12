//给你很多个单词，然后给你一段字符串，问你有多少个单词在这个字符串中出现过
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
	//nxt为字典树, fail相当于kmp中的nxt数组, end对单词结尾做标记 
	int root, L;  //L相当于字典树中的sz ，root为根节点（即；0） 
	int newnode() //初相当于始化一个字典树上的节点 
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
	void insert(char buf[]) //大致于字典树插入过程相同 
	{
		int len = strlen(buf);
		int now = root;
		for (int i = 0;i < len;i++)
		{
			int x = buf[i] - 'a';
			if (nxt[now][x] == -1) nxt[now][x] = newnode();
			now = nxt[now][x];
		}
		end[now]++; //在单词结尾处做标记 
	}
	void build()  //相当于kmp的操作 
	{
		queue<int>que;
		fail[root] = root; //根节点初始化为0(即其本身)
		for (int i = 0;i < 26;i++)
		{
			if (nxt[root][i] == -1) nxt[root][i] = root;
			else //Trie中已经构建的节点 
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
				if (nxt[now][i] == -1) //无后继点 
					nxt[now][i] = nxt[fail[now]][i];//类似于kmp中求nxt数组一样 
				else //存在下一个节点 
				{
					int x = nxt[now][i];
					fail[x] = nxt[fail[now]][i];
					//失配指针指向他父节点的失配指针的下一个相同字符处 
					que.push(x);
				}
			}
		}
	}
	int query(char buf[]) //相当于字典树中的访问操作 
	{
		int len = strlen(buf);
		int now = root;
		int res = 0;
		for (int i = 0;i < len;i++)
			//沿着整个文本串移动,每移动到一个字符（节点） 时，通过失配指针不断找寻模式串 ，重点为源头,找到一个就将其标记清除 
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
		return res; //返回单词个数 
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