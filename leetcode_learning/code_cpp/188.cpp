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

//一般思路：
//dp[k][i]表示前i天交易k次的最大收益

//百度面试的时候给了个更简单的方法，把卖出和买入分开计算，即共有2k次操作：
//dp[k][i] = max(dp[k][i-1], max_j(v[i]-v[j]+dp[k-1][j]))
//买
//dp[k][i] = max(dp[k][i-1], -v[i]+dp[k-1][j]))
//卖
//dp[k][i] = max(dp[k][i-1], v[i]+dp[k-1][j]))
int fun(vector<int> v, int k)
{
    int size = v.size();
    vector<vector<int>> dp(2*k+1, vector<int>(size+1,INT_MIN));
    
    for(int count=1;count<=2*k;count++)
        for(int i=1;i<=size;i++)
        {
            if(count%2==1)
                dp[count][i] = max(dp[count][i-1], -v[i]+dp[count-1][i]);
            else
                dp[count][i] = max(dp[count][i-1], v[i]+dp[count-1][i]);
        }
    return dp[2*k][size];
}

