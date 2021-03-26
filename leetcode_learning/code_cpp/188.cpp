class Solution {
public:
    int maxProfit(int count, vector<int>& prices) {
        int size = prices.size();
        if(size==0)
            return 0;
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
        //找各个交易次数的利润最大值
        int result = dp[0][size-1];
        for(int k=0;k<=count;k++)
        {
            //cout<<dp[k][size-1]<<endl;
            result = max(result,dp[k][size-1]);
        }
        return result;
    }
};