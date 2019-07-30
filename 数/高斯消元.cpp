const int MAXN=100+5;
const double EPS=1e-7;
double a[MAXN][MAXN];
//数组的有效范围是[0,equ),[0,val]因为想了想还是把x放在里面比较方便
int Gauss(int equ,int val)
{
    int maxrow,r,c,x_num;
    //每一次对一个未知数进行消元
    for(r=c=0;r<equ&&c<val;++c)
    {
        maxrow=r;
        for(int i=r+1;i<equ;++i)
            if(fabs(a[i][c])>fabs(a[maxrow][c])) maxrow=i;
        //当前未知数每一个未处理的行都为0，产生了自由未知数，换下一个未知数
        if(fabs(a[maxrow][c])<EPS) continue;
        if(maxrow!=r)
            for(int i=c;i<=val;++i)    swap(a[r][i],a[maxrow][i]);
        //目标还算明确，化成行阶梯形（上三角形），所以这里我们不对自己进行化简
        for(int i=r+1;i<equ;++i) if(fabs(a[i][c])>EPS)
          for(int j=val;j>=c;--j) A[i][j]-=A[i][c]/A[r][c]*A[r][j];
        //一行消完再消下一行，前面的continue就是为了躲避这句话
        ++r;
    }
    //存在(0 0 0 0 0 0 d[j][c]) (d[j][c] != 0) 的情况，方程无解
    for(int i=r;i<equ;++i) if(fabs(a[i][val])>EPS) return -1;
    //这部分是自己加的，要是线性无关的方程数没有未知数那么多，貌似就是无穷组解了啊，先写在这里
    if(r<val) return 0;
    //接下来枚举每一列（每一个未知数），c>=1就够了，我们没必要处理第一列，因为当其它列处理完的时候，第一列就不需要处理了
    for(c=val-1;c>=1;--c)
    {
        for(r=c-1;r>=0;--r) if(fabs(a[r][c])>EPS)
        {
            a[r][val]-=a[r][c]/a[c][c]*a[c][equ];
//            a[r][c]=0;
        }
        a[c][val]/=a[c][c];
//        a[c][c]=1;
    }
     return 1;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;++i)
            for(int j=0;j<=m;++j)
                scanf("%lf",&a[i][j]);
        Gauss(n,m);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<=m;++j)
                printf("%f ",a[i][j]);
            putchar(10);
        }
    }
}
