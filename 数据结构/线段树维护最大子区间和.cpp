using namespace std;
typedef long long LL;
const int INF=1e9+7,N=5e5+10,MAXNODE=N<<2,MAXM=1e5+10;
int n;
LL tmp[MAXNODE];
struct node{
    LL sum,maxl,maxr,maxv;
	//1.　区间最大字段和
	//2.　从该区间的左端点开始的最大字段和（一定包括该区间左端点）
	//3.   从该区间的右端点开始的最大字段和（同理一定包括该区间右端点）
    node(){
        sum=maxl=maxr=maxv=0;
    }
}A[MAXNODE];
inline void push_up(int x){
    A[x].sum=A[x<<1].sum+A[x<<1|1].sum;
    A[x].maxl=max(A[x<<1].maxl,A[x<<1].sum+A[x<<1|1].maxl);
    A[x].maxv=max(A[x<<1].maxr+A[x<<1|1].maxl,max(A[x<<1].maxv,A[x<<1|1].maxv));
    A[x].maxr=max(A[x<<1|1].maxr,A[x<<1].maxr+A[x<<1|1].sum);
}
void init(int x,int l,int r){
    if(l==r){
        A[x].sum=A[x].maxl=A[x].maxr=A[x].maxv=tmp[l];
        return;
    }
    int mid=(l+r)>>1;
    init(x<<1,l,mid);
    init(x<<1|1,mid+1,r);
    push_up(x);
}
void update(int x,int l,int r,int q,LL c){
    if(l==r){
        if(l==q)
            A[x].sum=A[x].maxl=A[x].maxr=A[x].maxv=c;
        return;
    }
    int mid=(l+r)>>1;
    if(q<=mid)
        update(x<<1,l,mid,q,c);
    else
        update(x<<1|1,mid+1,r,q,c);
    push_up(x);
}
node query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr){
        return A[x];
    }
    int mid=(l+r)>>1;
    if(qr<=mid)
        return query(x<<1,l,mid,ql,qr);
    if(ql>mid)
        return query(x<<1|1,mid+1,r,ql,qr);
    node left=query(x<<1,l,mid,ql,qr),right=query(x<<1|1,mid+1,r,ql,qr),ret;
    ret.maxv=max(left.maxr+right.maxl,max(left.maxv,right.maxv));
    ret.maxl=max(left.maxl,left.sum+right.maxl);
    ret.maxr=max(right.maxr,left.maxr+right.sum);
    return ret;
}
int main(){
	 scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",tmp+i);
    init(1,1,n);
	cin>>l>>r;
	query(1,1,n,l,r).maxv);//查询l-r最大子区间和
	cin>>p>>val;
    update(1,1,n,p,val);//第p个值变成val
    return 0;
}