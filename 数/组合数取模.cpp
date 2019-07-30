long long fac[maxn],inv[maxn];//这里的maxn视具体数据范围而定
int n;
long long pow(long long x,int k)//快速幂，为求一个逆元而准备
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans* x%mod;
        x=x*x%mod;
        k>>=1;
    } 
    return ans;
} 
void init()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%mod;//线性扫一遍求i的阶乘的逆元
     inv[n]=pow(fac[n],mod-2);//求n的阶乘对于mod的逆元
     for(int i=n-1;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%mod;//这个技巧就是通过最大的n的阶乘的逆元来求所有小于n的阶乘的逆元，也是线性扫一遍  
}
long long get(int n,int m)//然后直接用上面预处理的数组即可
{
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}