const int MAXN=100+5;
const double EPS=1e-7;
double a[MAXN][MAXN];
//�������Ч��Χ��[0,equ),[0,val]��Ϊ�����뻹�ǰ�x��������ȽϷ���
int Gauss(int equ,int val)
{
    int maxrow,r,c,x_num;
    //ÿһ�ζ�һ��δ֪��������Ԫ
    for(r=c=0;r<equ&&c<val;++c)
    {
        maxrow=r;
        for(int i=r+1;i<equ;++i)
            if(fabs(a[i][c])>fabs(a[maxrow][c])) maxrow=i;
        //��ǰδ֪��ÿһ��δ������ж�Ϊ0������������δ֪��������һ��δ֪��
        if(fabs(a[maxrow][c])<EPS) continue;
        if(maxrow!=r)
            for(int i=c;i<=val;++i)    swap(a[r][i],a[maxrow][i]);
        //Ŀ�껹����ȷ�������н����Σ��������Σ��������������ǲ����Լ����л���
        for(int i=r+1;i<equ;++i) if(fabs(a[i][c])>EPS)
          for(int j=val;j>=c;--j) A[i][j]-=A[i][c]/A[r][c]*A[r][j];
        //һ������������һ�У�ǰ���continue����Ϊ�˶����仰
        ++r;
    }
    //����(0 0 0 0 0 0 d[j][c]) (d[j][c] != 0) ������������޽�
    for(int i=r;i<equ;++i) if(fabs(a[i][val])>EPS) return -1;
    //�ⲿ�����Լ��ӵģ�Ҫ�������޹صķ�����û��δ֪����ô�࣬ò�ƾ�����������˰�����д������
    if(r<val) return 0;
    //������ö��ÿһ�У�ÿһ��δ֪������c>=1�͹��ˣ�����û��Ҫ�����һ�У���Ϊ�������д������ʱ�򣬵�һ�оͲ���Ҫ������
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
