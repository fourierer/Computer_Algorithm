#include<iostream>
#include<vector>

using namespace std;

//将和视为要凑成的金额数，完全平方数视为硬币，和零钱兑换一样的完全背包问题
//dp[i]表示组成和为n的最少完全平方和数
//dp[i] = min{dp[i], dp[i-square[j]]},j=0,1,...,n-1
class Solution {
public:
    int numSquares(int n) {
        for(int i=1;i*i<=n;i++)
            square.push_back(i*i);
        //for(int i=0;i<square.size();i++)
            //cout<<square[i]<<endl;
        return pack(square, n);
    }
private:
    vector<int> square;
    int pack(vector<int> square, int n)
    {
        vector<int> dp(n+1, INT_MAX-1);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<square.size();j++)
            {
                if(i>=square[j])
                    dp[i] = min(dp[i], dp[i-square[j]]+1);
            }
            //cout<<dp[i]<<endl;
        }
        if(dp[n]>=0&&dp[n]<=n)
            return dp[n];
        return -1;
    }
};


//双循环遍历
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};

