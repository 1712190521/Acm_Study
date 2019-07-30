inline void prep(){ //预处理组合数
for(int i=0;i<=50;++i) C[i][0]=1;
for(int i=1,j;i<=50;++i) for(j=1;j<=50;++j)
	C[i][j]=C[i-1][j-1]+C[i-1][j];
}