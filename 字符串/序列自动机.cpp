//��Ҫ������ж�һЩ�ַ����ǲ���ԭ���������е�����
int nxt[maxn][30];
int now[30];
char s[maxn];
void init()
{
    //�����Զ���Ԥ����
    memset(now, -1, sizeof now);            //mow_i��ʾ��i����ĸ��ԭ���дӺ���ǰ������ֵ�λ��
    int len = strlen(s);
    --len;
    for(int i = len; ~i; --i)               //����ÿһ���ַ�
    {
        for(int j = 0; j < 26; ++j)        //�ҳ���i���ַ������26����ĸ������ֵ��ַ���λ��
            nxt[i][j] = now[j];
        now[s[i] - 'a'] = i;                //�õ�ǰ�ַ����µ�ǰ�ַ���ԭ���дӺ���ǰ������ֵ�λ��
    }
}
/*����
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
���
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
            nextc[i-1][j]=nextc[i][j];  //str i-1λ�ü̳�str iλ�õ��������ַ������λ���ǵڼ��� 
        }
        nextc[i-1][s[i]-'a']=i; // str i-1λ����str[i]�ַ������λ�ñ�Ϊ��i��. 
    }
    int t;
    cin>>t;
    while(t--){
        scanf("%s",str1);
        int len1=strlen(str1);
        bool flag=false;
        for(int i=0,now=0;i<len1;i++){//now��0��ʼ,��Ϊnextc[0]����˵�s�������ַ������λ�� 
            now=nextc[now][str1[i]-'a'];
            if(now==0){//�������;������û���������Ҿ���û�� 
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