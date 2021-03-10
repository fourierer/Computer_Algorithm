#include<iostream>
#include<vector>
#include<math>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int max_profit = 0;
        int min_prices = INT_MAX;
        for(int i=0; i<prices.size(); i++)
        {
            max_profit = max(max_profit, prices[i]-min_prices);
            min_prices = min(min_prices, prices[i]);
        }
        return max_profit;
    }
};

