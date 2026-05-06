#include<iostream>
#include<vector>

using namespace std;

//设dp[i]表示打出i个'A'最少需要多少操作
//dp[i] = min{dp[j]+i/j}，其中j|i；即在i的因子j中进行动态规划，当有j个'A'时，可以先复制，再粘贴i/j-1次，共i/j次操作
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, n);//n个'A'最多操作n次
        dp[0] = 0;
        dp[1] = 0;
        for(int i=0;i<=n;i++)
        {
            //遍历i的因子
            for(int j=1;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    dp[i] = min(dp[i], min(dp[j]+i/j, dp[i/j]+j));//考虑因子i/j和因子j
                }
            }
        }
        return dp[n];
    }
};