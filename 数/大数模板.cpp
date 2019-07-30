�����������
string sum(string s1,string s2)
{
	if(s1.length()<s2.length())
	{
		string temp=s1;
		s1=s2;
		s2=temp;
	}
	int i,j;
	for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--)
	{
		s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //ע��ϸ��
		if(s1[i]-'0'>=10)
		{
			s1[i]=char((s1[i]-'0')%10+'0');
			if(i) s1[i-1]++;
			else s1='1'+s1;
		}
	}
	return s1;
}
��������������
string Except(string s,int x)  //��������������
{
    int cmp=0,ok=0;
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        cmp=(cmp*10+s[i]-'0');
        if(cmp>=x)
        {
            ok=1;
            ans+=(cmp/x+'0');
            cmp%=x;
        }
        else{
            if(ok==1)
                ans+='0';  //ע�����ﰡ�����ҳ�����
        }
    }
    return ans;
}
�����˷�
string Mult(string s,int x)  //��������������
{
    reverse(s.begin(),s.end());
    int cmp=0;
    for(int i=0;i<s.size();i++)
    {
        cmp=(s[i]-'0')*x+cmp;
        s[i]=(cmp%10+'0');
        cmp/=10;
    }
    while(cmp)
    {
        s+=(cmp%10+'0');
        cmp/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
string Multfa(string x,string y)  //�����˷�
{
    string ans;
    for(int i=y.size()-1,j=0;i>=0;i--,j++)
    {
        string tmp=Mult(x,y[i]-'0');
        for(int k=0;k<j;k++)
            tmp+='0';
        ans=sum(ans,tmp);
    }
    return ans;
}
string Remove_later(string s)   //ɾ��һ���ַ����ĺ�0
{
    int ok=1;
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i]=='0'){
            s.erase(i);
        }
        else if(s[i]=='.')
        {
            s.erase(i);
            ok=0;
        }
        else
            ok=0;
        if(ok==0)
            break;
    }
    return s;
}
string factorial(string s,int n)   //��������n�η�
{
    if(n==0)
        return "1";
    string cmp="",count="";
    long x=0,point=0;
    for(int i=0; i<s.size(); i++)
        if(s[i]!='.')
        {
            cmp+=s[i];
            x=x*10+(s[i]-'0');
        }
        else
            point=s.size()-1-i;
    for(int i=1; i<n; i++)
    {
        cmp=Multiply(cmp,x);
    }
    int ans_point=cmp.size()-n*point;
    if(ans_point<0)
    {
        count+='.';
        for(int i=ans_point; i!=0; i++)
            count+='0';
    }
    string::iterator it=cmp.begin();
    if(ans_point>=0&&ans_point<cmp.size())
        cmp.insert(it+ans_point,'.');
    count+=(Remove_later(cmp));
    return count;
}
�ַ���ȥ����0������ǰ��0�����ȷ�תȡ�󵼡�
string Remove_later(string s)   //ɾ��һ���ַ����ĺ�0
{
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i]=='0')
            s.erase(i);
        else
            break;
    }
    return s;
}
string sub(string str1,string str2)//�߾��ȼ���
{
    string str;
    int tmp=str1.length()-str2.length();
    int cf=0;
    for(int i=str2.length()-1;i>=0;i--)
    {
        if(str1[tmp+i]<str2[i]+cf)
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0'+10)+str;
            cf=1;
        }
        else
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0')+str;
            cf=0;
        }
    }
    for(int i=tmp-1;i>=0;i--)
    {
        if(str1[i]-cf>='0')
        {
            str=char(str1[i]-cf)+str;
            cf=0;
        }
        else
        {
            str=char(str1[i]-cf+10)+str;
            cf=1;
        }
    }
    str.erase(0,str.find_first_not_of('0'));//ȥ������ж����ǰ��0
    return str;
}