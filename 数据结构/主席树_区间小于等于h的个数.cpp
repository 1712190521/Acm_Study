#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn=1e5+100;
vector<int> v;
int n,m,a[maxn],rt[maxn],tot;
struct node
{
    int l,r,sum;
}T[maxn*20];
int getid(int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void build(int &o,int l,int r)
{
    o=++tot;
    T[o].sum=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(T[o].l,l,mid);
    build(T[o].r,mid+1,r);
}
void update(int l,int r,int &now,int last,int k)
{
    T[++tot]=T[last];
    now=tot;
    T[now].sum++;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(k<=mid) update(l,mid,T[now].l,T[last].l,k);
    else update(mid+1,r,T[now].r,T[last].r,k);
}
int query(int l,int r,int x,int y,int k)
{
    if(l==r) return T[y].sum-T[x].sum;
    int mid=(l+r)>>1;
    if(k<=mid) return query(l,mid,T[x].l,T[y].l,k);
    else
    {
        int ret=0;
        ret+=T[T[y].l].sum-T[T[x].l].sum;
        ret+=query(mid+1,r,T[x].r,T[y].r,k);
        return ret;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        v.clear();
        tot=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        build(rt[0],1,n);
        for(int i=1;i<=n;i++)
            update(1,n,rt[i],rt[i-1],getid(a[i]));
        printf("Case %d:\n",kase);
        for(int i=1;i<=m;i++)
        {
            int l,r,h;
            scanf("%d%d%d",&l,&r,&h);
            l++,r++;
            int k=upper_bound(v.begin(),v.end(),h)-v.begin();//v中有k个元素小于等于h
            //upper的返回值是指向键值<=key的最后一个元素的后一个元素。 
            if(!k) printf("0\n");
            else
                printf("%d\n",query(1,n,rt[l-1],rt[r],k));
        }
    }
    return 0;
}
