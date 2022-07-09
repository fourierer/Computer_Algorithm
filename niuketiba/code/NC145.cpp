#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        int k = vw.size();//k个物品
        //dp[i][v]表示包空v时，前i个物品的最大重量
        //dp[i][v]=max{dp[i-1][v], dp[i-1][v-vi] + wi}
        vector<vector<int>> dp(k+1, vector<int>(V+1,0));
        for(int i=1;i<=k;i++)
            for(int v=1;v<=V;v++)
            {
                //如果当前空的空间小于当前物品的重量，那么不放当前的物品
                if(v-vw[i-1][0]<0)
                    dp[i][v] = dp[i-1][v];
                else
                    dp[i][v] = max(dp[i-1][v], dp[i-1][v-vw[i-1][0]] + vw[i-1][1]);
            }
        return dp[k][V];
    }
};