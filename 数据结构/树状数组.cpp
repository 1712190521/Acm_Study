int C[N*3];
int lowbit(int x){
	return x&(-x);
}
//��ǰx���
int getsum(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))
		ans+=C[i];
	return ans;
}
//�޸�
void add(int x,int y)
{
	for(int i=x;i<=n*3;i+=lowbit(i))
		C[i]+=y;
}