//扩展KMP解决的问题：定义母串S和子串T，S的长度为n，T的长度为m；
//求字符串T与字符串S的每一个后缀的最长公共前缀；
//也就是说，设有extend数组：extend[i]表示T与S[i,n-1]的最长公共前缀，要求出所有extend[i](0<=i<n)。
const int MAX=100010; //字符串长度最大值
int Next[MAX],extend[MAX];//next[i]表示T[i,m-1]和T的最长公共前缀长度
void getNext(char str[])
{
    int i=0,j,po,len=strlen(str);
    next[0]=len; //初始化next[0]
    while(str[i]==str[i+1] && i+1<len) i++; next[1]=i; //计算next[1]
    po=1; //初始化po的位置
    for(i=2;i<len;i++)
    {
        if(next[i-po]+i < next[po]+po) //第一种情况，可以直接得到next[i]的值
            next[i]=next[i-po];
        else //第二种情况，要继续匹配才能得到next[i]的值
        {
            j = next[po]+po-i;
            if(j<0) j=0; //如果i>po+next[po],则要从头开始匹配
            while(i+j<len && str[j]==str[j+i]) j++; next[i]=j;
            po=i; //更新po的位置
        }
    }
}
//计算extend数组
void EXKMP(char s1[],char s2[])
{
    int i=0,j,po,len=strlen(s1),l2=strlen(s2);
    getNext(s2); //计算子串的next数组
    while(s1[i]==s2[i] && i<l2 && i<len) i++; extend[0]=i;
    po=0; //初始化po的位置
    for(i=1;i<len;i++)
    {
        if(next[i-po]+i < extend[po]+po) //第一种情况，直接可以得到extend[i]的值
            ex[i]=next[i-po];
        else //第二种情况，要继续匹配才能得到extend[i]的值
        {
            j = extend[po]+po-i;
            if(j<0) j=0; //如果i>extend[po]+po则要从头开始匹配
            while(i+j<len && j<l2 && s1[j+i]==s2[j]) j++; extend[i]=j;
            po=i; //更新po的位置
        }
    }
}