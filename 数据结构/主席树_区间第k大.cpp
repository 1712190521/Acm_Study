#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int  MAXN = 100010;
const int N = MAXN*40;
int n,m,q,tot;
int T[MAXN],A[MAXN],t[MAXN];
int lson[N],rson[N],sum[N];
vector<int>V;
int getid(int x) //离散化
{
    return lower_bound(V.begin(),V.end(),x)-V.begin()+1;
}
int build(int l,int r)  //建立一棵空树
{
    int rt = tot++;
    sum[rt] = 0;
    if(l!=r){
        int mid=(l+r)>>1;
        lson[rt] = build(l,mid);
        rson[rt] = build(mid+1,r);
    }
    return rt;
}

int update(int rt,int pos)  //把数组中的元素一次加入新的线段树中
{
    int nrt = tot++;
    int tmp = nrt;
    sum[nrt]  = sum[rt]+1;
    int l=1,r=m;
    while(l<r) {
        int mid = (l+r)>>1;
        if(pos<=mid) {
            lson[nrt] = tot++;
            rson[nrt] = rson[rt];
            nrt = lson[nrt];
            rt = lson[rt];
            r = mid;
        }else {
            rson[nrt] = tot++;
            lson[nrt] = lson[rt];
            nrt = rson[nrt];
            rt = rson[rt];
            l=mid+1;
        }
        sum[nrt] = sum[rt]+1;
    }
    return tmp;
}

int query(int lrt,int rrt,int k)
{
    int l=1,r=m;
    while(l<r) {
        int mid = (l+r)>>1;
        int cnt = sum[lson[rrt]] - sum[lson[lrt]];
        if(cnt>=k) {
            r = mid;
            lrt = lson[lrt];
            rrt = lson[rrt];
        } else {
            l = mid+1;
            k-=cnt;
            lrt = rson[lrt];
            rrt = rson[rrt];
        }
    }
    return l;
}
int main()
{//freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&q);tot=0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&A[i]);
        V.push_back(A[i]);
    }
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()),V.end());
    m=V.size();
    T[0] = build(1,m);
    for(int i=1;i<=n;i++) {
        T[i] = update(T[i-1],getid(A[i]));
    }
    while(q--) {
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        printf("%d\n",V[query(T[x-1],T[y],k)-1]);
    }
    return 0;
}