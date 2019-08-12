int tol; //节点个数 
ll val[32*MAXN]; //点的值 
int ch[32*MAXN][2]; //边的值 
void init()
{ //初始化 
    tol=1;
    ch[0][0]=ch[0][1]=0;
}
void insert(ll x)
{ //往 01字典树中插入 x 
    int u=0;
    for(int i=32;i>=0;i--)
    {
        int v=(x>>i)&1;
        if(!ch[u][v])
        { //如果节点未被访问过 
            ch[tol][0]=ch[tol][1]=0; //将当前节点的边值初始化 
            val[tol]=0; //节点值为0，表示到此不是一个数 
            ch[u][v]=tol++; //边指向的节点编号 
        }
        u=ch[u][v]; //下一节点 
    }
    val[u]=x; //节点值为 x，即到此是一个数 
}
ll query(ll x)
{ //查询所有数中和 x异或结果最大的数 
    int u=0;
    for(int i=32;i>=0;i--)
    {
        int v=(x>>i)&1;
        //利用贪心策略，优先寻找和当前位不同的数 
        if(ch[u][v^1]) u=ch[u][v^1];
        else u=ch[u][v];
    }
    return val[u]; //返回结果 
}