#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define maxn 500005
using namespace std;
bool vis[maxn];
int dis[maxn],h[maxn];
int ecnt=0;
int n,m,s;
struct data
{
    int to,next,w;
}e[maxn];
void ins(int a,int b,int c)
{
    e[++ecnt].to=b;
    e[ecnt].next=h[a];
    h[a]=ecnt;
    e[ecnt].w=c;
}
queue<int>q;
void spfa(int ask){
    q.push(ask);
    memset(vis,0,sizeof(vis));
    memset(dis,127/3,sizeof(dis));
    dis[ask]=0;
    vis[ask]=1;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        vis[x]=0;
        for(int i=h[x];i;i=e[i].next)
        {
            if(dis[e[i].to]>dis[x]+e[i].w)
            {
                dis[e[i].to]=dis[x]+e[i].w;
                if(!vis[e[i].to])
                {
                    vis[e[i].to]=1;
                    q.push(e[i].to);
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m>>s;
    for(int a,b,c,i=1;i<=m;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        ins(a,b,c);
    }
    spfa(s);
    printf("%d",dis[i]);
    puts("");
    return 0;
}

SLF优化