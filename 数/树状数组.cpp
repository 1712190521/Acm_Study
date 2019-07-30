int C[N*3];
int lowbit(int x){
	return x&(-x);
}
//求前x项和
int getsum(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))
		ans+=C[i];
	return ans;
}
//修改
void add(int x,int y)
{
	for(int i=x;i<=n*3;i+=lowbit(i))
		C[i]+=y;
}