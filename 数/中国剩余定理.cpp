///返回特解的值；
void  gcd_ex(LL a,LL b,LL &x,LL &y)
{
    if(b==0) {x=1;y=0;}
    else { gcd_ex(b,a%b,y,x); y-=a/b*x;}
}
LL CRT(LL *a,LL *m,LL n)
{
    LL M=1,res=0;
    for(int i=0;i<n;i++) M*=m[i];
    for(int i=0;i<n;i++)
    {
        LL x,y,temp=M/m[i];
        gcd_ex(temp,m[i],x,y);
        res=(res+temp*x*a[i])%M;
    }
    return (res+M)%M;
}
///拓展中国剩余定理
/// 用于计算x==a[i](mod m[i]) 的一个特解，方程不必要求所有的模两两互质。
///方法：将方程两两合并。
LL   gcd_ex(LL a,LL b,LL &x,LL &y)
{
    if(b==0) {x=1;y=0;return a;}
    LL d=gcd_ex(b,a%b,y,x);
    y-=a/b*x;
return d;
}
inline LL mod(LL a,LL m){return a%m+(a%m>0?0:m);}
LL CRT_ex(int n,int a[],int m[])
{
    if(n==1&&a[0]==0) return m[0];
    LL ans=a[0],lcm=m[0];
    bool flag=true;
    for(int i=1;i<n;i++)
    {
        LL x,y,gcd;
        gcd=gcd_ex(lcm,m[i],x,y);
        if((a[i]-ans)%gcd){flag=false;break;}
        LL temp=lcm*mod((a[i]-ans)/gcd*x,m[i]/gcd);
        lcm=lcm/gcd*m[i];
        ans=mod(ans+temp,lcm);
    }
    return flag?ans:-1;
}
