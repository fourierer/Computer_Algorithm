#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for(int i=0;i<prices.size()-1;i++)
        {
            int diff = prices[i+1]-prices[i];
            if(diff>0)
                max_profit += diff;
        }
        return max_profit;
    }
};