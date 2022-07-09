#include<iostream>
#include<vector>

using namespace std;

//思路
//1.动态规划：dp[i][j]表示str1的前i个字符编辑成str2的前j个字符需要的最小代价
//2.初始状态：dp[i][0] = i*dc，i次删除；dp[0][i] = i*ic，i次插入
//3.状态转移方程：
//当str[i]==str[j]时：dp[i][j] = dp[i-1][j-1]，不需要额外操作
//当str[i]!=str[j]时：dp[i][j] = min(insert, delete, replace)
//int insert = dp[i][j-1] + ic; i个编辑成j-1个字符，再插入一个j
//int delete = dp[i-1][j] + dc; i-1个编辑成j个字母，再删除一个i
//int replace = dp[i-1][j-1] + rc; i-1个编辑成j-1个字母，再将i替换成j

class Solution {
public:
    /**
     * min edit cost
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @param ic int整型 insert cost
     * @param dc int整型 delete cost
     * @param rc int整型 replace cost
     * @return int整型
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        // write code here
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
            dp[i][0] = i*dc;
        for(int j=1;j<=n;j++)
            dp[0][j] = j*ic;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    int Insert = dp[i][j-1] + ic;
                    int Delete = dp[i-1][j] + dc;
                    int Replace = dp[i-1][j-1] + rc;
                    dp[i][j] = min(min(Insert, Delete),Replace);
                }
            }
        return dp[m][n];
    }
};


