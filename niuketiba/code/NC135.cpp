#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

//超时，通过202/214个测试用例
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = 2;//交易的次数，有普适性
        int size = prices.size();
        vector<vector<int>> dp(count+1, vector<int>(size,0));//初始化(k+1)*size的全0数组
        //对交易次数遍历
        for(int k=1;k<=count;k++)
        {
            //对天数遍历
            for(int i=1;i<size;i++)
            {
                //假设第k次交易是在第j天买入，第i天卖出，找最大利润
                int max_profit = prices[i]-prices[0];//初始化最大利润是第一天买入，这里是在i循环的里面初始化的
                for(int j=1;j<=i;j++)
                    max_profit = max(max_profit,prices[i]-prices[j]+dp[k-1][j-1]);
                dp[k][i] = max(dp[k][i-1], max_profit);
            }
        }
        return dp[count][size-1];
    }
};

//优化减少一个循环，在上面代码中要求第i天之前的可以获得最大利润的第j天
//这里转换下思路，求最大利润相当于求最小成本，即prices[i]-prices[j]+dp[k-1][j-1]=prices[i]-(prices[j]-dp[k-1][j-1])
//在对i循环时，就可以维护一个最小成本
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = 2;//交易的次数，有普适性
        int size = prices.size();
        vector<vector<int>> dp(count+1, vector<int>(size,0));//初始化(k+1)*size的全0数组
        //对交易次数遍历
        for(int k=1;k<=count;k++)
        {
            //对天数遍历
            int min_cost = prices[0];//初始化最小成本是第一天价格，这里是在i循环的外面初始化的
            for(int i=1;i<size;i++)
            {
                //假设第k次交易是在第j天买入，第i天卖出，找最大利润
                min_cost = min(min_cost,prices[i]-dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i]-min_cost);
            }
        }
        return dp[count][size-1];
    }
};

