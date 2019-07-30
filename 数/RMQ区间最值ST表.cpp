void makeRmqIndex(int n,ll b[]) //返回最小值对应的下标
{
    int i,j;
    for(i=0;i<=n;i++)
        dp[i][0]=i;
    for(j=1;(1<<j)<=n;j++)
        for(i=1;i+(1<<j)-1<=n;i++)
            dp[i][j]=b[dp[i][j-1]] < b[dp[i+(1<<(j-1))][j-1]]? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
}
int rmqIndex(int s,int v,ll b[])
{
    int k=(int)(log((v-s+1)*1.0)/log(2.0));
    return b[dp[s][k]]<b[dp[v-(1<<k)+1][k]]? dp[s][k]:dp[v-(1<<k)+1][k];
}