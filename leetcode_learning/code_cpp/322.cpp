#include<iostream>
#include<vector>

using namespace std;

//思路：dp[i]表示金额为i所需要的最少硬币数
//dp[i] = min{dp[i],dp[i-coins[j]]+1},j=0,1,2,...,n-1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);//后续有dp[i-coins[j]]+1操作，INT_MAX+1不能用int表示，会报错
        dp[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i>=coins[j])
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        if(dp[amount]>=0&&dp[amount]<=amount)
            return dp[amount];
        return -1;
    }
};


