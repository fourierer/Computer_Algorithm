#include<iostream>
#include<string>
#include<vector>

using namespace std;


//dp[i][j]��ʾs[i]��s[j]������������еĳ���
//k=0��dp[i][j]����һ��Ϊ1
//k=1��dp[i][j]ȡ����s[i]��s[j]�Ƿ����
//k>1��dp[i][j]ȡ����dp[i+1][j-1]:
//(1)���s[i]==s[j]����dp[i][j] = dp[i+1][j-1] + 2
//(2)���s[i]!=s[j]����s[i]��s[j]������ͬʱΪ���������е���β��dp[i][j] = max(dp[i+1][j], dp[i][j+1])
//���շ���dp[0][n-1]
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


