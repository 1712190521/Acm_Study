//����dp�����������Ͻ��ж�̬�滮�����һ�������ϵ����Ž⡣��Ҫ��ͨ���ϲ�С����� ���Ž�����ó����������������Ž��dp�㷨��
for(int len = 1;len<=n;len++){//ö�ٳ���
        for(int j = 1;j+len<=n+1;j++){//ö����㣬ends<=n
            int ends = j+len - 1;
            for(int i = j;i<ends;i++){//ö�ٷָ�㣬����С�������Ž�
                dp[j][ends] = min(dp[j][ends],dp[j][i]+dp[i+1][ends]+something);
            }
        }
    }