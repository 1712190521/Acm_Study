#pragma GCC optimize(2)
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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep2(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
using namespace std;
const int N = 5000;
const int mod = 998244353;
const int  INF = 0x3f3f3f3f;
const ll inf=1ll<<62-1ll;
inline void read(int& x) {
	x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef ONLINE_JUDGE
#else
	freopen("./std.in", "r", stdin);
#endif
	read(n); read(m); read(s); read(t);
	return 0;
}
