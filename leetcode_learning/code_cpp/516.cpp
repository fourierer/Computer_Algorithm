#include<iostream>
#include<string>
#include<vector>

using namespace std;


//dp[i][j]表示s[i]到s[j]中最长回文子序列的长度
//k=0，dp[i][j]长度一定为1
//k=1，dp[i][j]取决于s[i]与s[j]是否相等
//k>1，dp[i][j]取决于dp[i+1][j-1]:
//(1)如果s[i]==s[j]，则dp[i][j] = dp[i+1][j-1] + 2
//(2)如果s[i]!=s[j]，则s[i]和s[j]不可能同时为回文子序列的首尾，dp[i][j] = max(dp[i+1][j], dp[i][j+1])
//最终返回dp[0][n-1]
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        //k = j - i
        for(int k=0;k<n;k++)
            for(int i=0;i+k<n;i++)
            {
                int j = i+k;
                if(k==0)
                    dp[i][j] = 1;
                else if(k==1)
                {
                    if(s[i]==s[j])
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 1;
                }
                else
                {
                    if(s[i]==s[j])
                        dp[i][j] = dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        return dp[0][n-1];
    }
};


