#include<iostream>
#include<vector>

using namespace std;

//动态规划
//dp[i]表示组成金额i的组合数
//dp[i] = sum{dp[i-coin[j]]},j=0,1,...,n-1
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;//组成金额0的只有一种
        for(int j=0;j<coins.size();j++)
        {
            for(int i=1;i<=amount;i++)
            {
                if(i>=coins[j])
                    dp[i] += dp[i-coins[j]];
            }
        }
        // for(int i=0;i<dp.size();i++)
        //     cout<<dp[i]<<endl;
        return dp[amount];
    }
};

