//主要解决：判断一些字符串是不是原串的子序列的问题
int nxt[maxn][30];
int now[30];
char s[maxn];
void init()
{
    //序列自动机预处理
    memset(now, -1, sizeof now);            //mow_i表示第i个字母在原串中从后向前最晚出现的位置
    int len = strlen(s);
    --len;
    for(int i = len; ~i; --i)               //处理每一个字符
    {
        for(int j = 0; j < 26; ++j)        //找出第i个字符后面的26个字母最早出现的字符的位置
            nxt[i][j] = now[j];
        now[s[i] - 'a'] = i;                //用当前字符更新当前字符在原串中从后向前最晚出现的位置
    }
}
/*输入
noiauwfaurainairtqltqlmomomo
8
rain
air
tql
ntt
xiaobai
oiiiooo
orzcnzcnznb
ooooo
输出
Yes
Yes
Yes
Yes
No
Yes
No
No*/
#include<iostream>
#include<string>
#include<string.h>
#include<cstdio>
using namespace std;
int nextc[1000010][30];
char str1[1000010];
char s[1000010]; 
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=len;i>=1;i--){
        for(int j=0;j<26;j++){
            nextc[i-1][j]=nextc[i][j];  //str i-1位置继承str i位置的离其它字符最近的位置是第几个 
        }
        nextc[i-1][s[i]-'a']=i; // str i-1位置离str[i]字符的最近位置变为第i个. 
    }
    int t;
    cin>>t;
    while(t--){
        scanf("%s",str1);
        int len1=strlen(str1);
        bool flag=false;
        for(int i=0,now=0;i<len1;i++){//now从0开始,因为nextc[0]里存了到s的所有字符的最近位置 
            now=nextc[now][str1[i]-'a'];
            if(now==0){//如果查找途中遇到没法继续查找就是没有 
                flag=true;
                break;
            }
        }
        if(flag){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }
    return 0;
}