#include<iostream>
#include<vector>

using namespace std;

//动态规划
//dp[i][j]表示i步后，指针在位置j的方案数，则0<=i<=step,0<=j<=min(arrLen-1,step),因为step后j最多到step位置
//根据题意有动态转移方程：dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1]
//边界条件：dp[0][0] = 1,dp[0][j] = 0,j=1,...,min(arrLen-1,step)
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int column = min(arrLen-1, steps);
        vector<vector<int>> dp(steps+1, vector<int>(column+1));
        dp[0][0] = 1;
        for(int i=1;i<=steps;i++)
            for(int j=0;j<=column;j++)
            {
                //dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];//直接相加可能会出现j-1,j+1出界的情况，需要条件判断
                dp[i][j] = dp[i-1][j];
                if(j-1>=0)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % 1000000007;
                if(j+1<=column)
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % 1000000007;
            }
        return dp[steps][0];
    }
};

//考虑到动态转移方程只涉及其中两行，可以优化内存空间
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int column = min(arrLen-1, steps);
        vector<int> dp(column+1);
        dp[0] = 1;
        for(int i=1;i<=steps;i++)
        {
            vector<int> dp_next(column+1);
            for(int j=0;j<=column;j++)
            {
                dp_next[j] = dp[j];
                if(j-1>=0)
                    dp_next[j] = (dp_next[j] + dp[j-1]) % 1000000007;
                if(j+1<=column)
                    dp_next[j] = (dp_next[j] + dp[j+1]) % 1000000007;
            }
            dp = dp_next;//vector<int>之间可以直接赋值
        }
        return dp[0];
    }
};

