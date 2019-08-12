//区间dp就是在区间上进行动态规划，求解一段区间上的最优解。主要是通过合并小区间的 最优解进而得出整个大区间上最优解的dp算法。
for(int len = 1;len<=n;len++){//枚举长度
        for(int j = 1;j+len<=n+1;j++){//枚举起点，ends<=n
            int ends = j+len - 1;
            for(int i = j;i<ends;i++){//枚举分割点，更新小区间最优解
                dp[j][ends] = min(dp[j][ends],dp[j][i]+dp[i+1][ends]+something);
            }
        }
    }