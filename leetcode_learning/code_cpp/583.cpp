#include<iostream>
#include<vector>
#include<string>

using namespace std;

//求最长子序列的长度，两个字符串到最长子序列要删除的字符数之和就是最少操作步数
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1;i<m+1;i++)
        {
            char w1 = word1[i-1];
            for(int j=1;j<n+1;j++)
            {
                char w2 = word2[j-1];
                if(w1==w2)
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int loss = m - dp[m][n] + n - dp[m][n];
        return loss;
    }
};
