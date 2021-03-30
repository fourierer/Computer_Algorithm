#include<iostream>
#include<string>
#include<vector>

using namespace std;

//计算两个字符串最长公共子序列的长度，而不是返回最长的公共子序列
class CommonSequence
{
public:
    int func(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1;i<m+1;i++)
        {  
            for(int j=1;j<n+1;j++)
            {
                if(str1[i]==str2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }  
        return dp[m][n];
    }
};