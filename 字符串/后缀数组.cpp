#include<functional>
#include<algorithm>
#include<iostream>
#include<cassert>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<stack>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std;
const int maxn = 1e6 + 5;
int sa[maxn], ranks[maxn], newranks[maxn], sum[maxn], key2[maxn], height[maxn];
//sa[ i ]=j表示排好序后排名第 i 的后缀是后缀 j
//ranks[ j ]=i表示后缀 j 排好序后的排名是 i
//height[i] = j: 表示排名为i 的后缀和排名为i−1 的后缀的最长公共前缀的长度为j
//H[i] = j: 表示后缀i与其比它排名前一名的后缀的最长公共前缀长度为j
//H数组有一个极其极其重要的性质:H[i]≥H[i−1]−1注意 : H[i]≥0
int n, m;
char  str[maxn];
bool cmp(int a, int b, int l)
{
	if (ranks[a] != ranks[b]) return false;//如果第一关键字不相同，直接返回不相同 
	if ((a + l > n and b + l <= n) or (a + l <= n and b + l > n)) return false;//如果第一关键字相同，但是其中只有一个有第二关键字，直接返回不相同 
	if (a + l > n and b + l > n) return true;//如果第一关键字相同，且都没有第二关键字，返回相同 
	return ranks[a + l] == ranks[b + l];//返回第二关键字相不相同 

}
void getHeight()
{
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ranks[i] == 1) continue;
		int j = sa[ranks[i] - 1];
		while (str[j + k] == str[i + k] and j + k <= n and i + k <= n) k++;
		height[ranks[i]] = k;
		if (k != 0) k--;
	}
}
void solv()
{
	n = strlen(str + 1);
	for (int i = 1; i <= n; i++) sum[ranks[i] = str[i]]++; //按照字典序初始化排名 
	m = max(n, 256);
	for (int i = 1; i <= m; i++) sum[i] += sum[i - 1];//前缀和，此时sum[i]=j表示的是小于等于i的关键字有j个(此时只有一个关键字) 
	for (int i = n; i >= 1; i--) sa[sum[ranks[i]]--] = i; //将分好类的原序列放入新序列中 
	for (int l = 1; l < n; l <<= 1)//倍增 
	{
		//l表示已知所有后缀按照前l个字符的排名，求所有后缀按照前l*2个字符的排名 
		int k = 0;
		for (int i = n - l + 1; i <= n; i++) key2[++k] = i;//如果没有第二关键字，直接放在序列的最前面 
		for (int i = 1; i <= n; i++) if (sa[i] > l) key2[++k] = sa[i] - l;//跳过不合法的第二关键字
		//注意，因为存储的是后缀j，所以存的是它的第一个字符的位置，并不是第二关键字的开头位置，因此sa[i]需要减l 
		for (int i = 1; i <= m; i++) sum[i] = 0;//初始化sum数组 
		for (int i = 1; i <= n; i++) sum[ranks[i]]++;//分类 
		for (int i = 1; i <= m; i++) sum[i] += sum[i - 1];//前缀和 
		for (int i = n; i >= 1; i--)
		{
			int j = key2[i];//key2中，后缀已经排好序了，但实际上在ranks数组中，存储的还是上一个位置的排名信息，因此要用到更新后的key2数组的信息 
			sa[sum[ranks[j]]--] = j;//从后往前，按照第一关键字分好的类别依次放入新序列中，同时保证了第二关键字小的较前 
		}
		int rk = 1;
		newranks[sa[1]] = rk;//计算排名，排序后的第一名的排名为1 
		for (int i = 2; i <= n; i++)
		{
			if (cmp(sa[i - 1], sa[i], l)) newranks[sa[i]] = rk;//如果当前这一名第一和第二关键字与前一名相同，那么它们的排名也是相同的 
			else newranks[sa[i]] = ++rk;//否则当前排名是前一个排名的后一位 
		}
		for (int i = 1; i <= n; i++) ranks[i] = newranks[i];//将当前排名覆盖以前的排名 
		if (rk == n) break;//剪枝 
	}
}
int main()
{
	scanf("%s", str + 1);
	solv();
	for (int i = 1; i <= n; i++) printf("%d%c", sa[i], i != n ? ' ' : '\n');
	return 0;
}