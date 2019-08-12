#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 60;
int N;
int Path[MAXN][MAXN];
int Set[MAXN];
int Ans;

bool is_clique(const int end, const int point)
{
	for (int i = 1; i<=end; ++i)
	{
		if (!Path[Set[i]][point])
		{
			return false;
		}
	}
	return true;
}
void dfs(int had, int now)
{
	if (had + N - now < Ans) return;
	for (int i = now; i <= N; i++)
		if (is_clique(had, i)) {
			Set[had + 1] = i;
			dfs(had + 1, i + 1);
		}
			if (had > Ans)
		Ans = had;
}
int main()
{
	while (scanf("%d", &N) && N) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &Path[i][j]);
		Ans = 0;
		dfs(0, 0);
		printf("%d\n", Ans);
	}
}


#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
 
 using namespace std;
 
const int MAXN=60;
int N;
int Path[MAXN][MAXN];
int Set[MAXN];//用以寻找一个可能集合
int Ans;
int DP[MAXN];
//判断新点是否与原集合里的点互相连通
bool is_clique( const int end, const int point )
{
    for( int i=1; i<end; ++i )
    {
        if( !Path[ Set[i] ][point] )
        {
            return false;
        }
    }
    return true;
}
//递归查找,查找算法简单明了,不再详说
void dfs( int depth, int now )
{
    if( depth+N-now+1 <= Ans||depth+DP[now] <=Ans )
    {
        return;
    }
    for( int i=now; i<=N; ++i )
    {
        if( is_clique(depth+1, i) )
        {
            Set[depth+1]=i;
            dfs( depth+1, i+1 );
        }
    }
    if( depth > Ans )
    {
        Ans=depth;
    }
}
int main()
{
//    freopen("a.in","r",stdin);
 
    while( scanf("%d", &N)!=EOF && N )
    {
        for( int i=1; i<=N; ++i )
        {
            for( int j=1; j<=N; ++j )
            {
                scanf("%d", &Path[i][j]);
            }
        }
        memset(DP,0,sizeof(DP));
        Ans=0;
        DP[N]=1;
        for(int i=N-1;i>=1;i--)
        {
            Set[1]=i;
            dfs( 1, i+1 );
            DP[i]=Ans;
        }
        printf("%d\n", DP[1]);
    }
    return 0;
}