#include<iostream>
#include<string>
#include<vector>

using namespace std;

//思路：
//动态规划：dp[i]表示前i个字符能解码的数量
//(1)当s[i-1]!='0'时，dp[i] += dp[i-1]
//(2)当i>1&&s[i-2]!='0'&&(s[i-2]-'0')*10 + (s[i-1]-'0')<=26时，dp[i] += dp[i-2]
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]!='0')
                dp[i] += dp[i-1];
            if(i>1&&s[i-2]!='0'&&(s[i-2]-'0')*10+s[i-1]-'0'<=26)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};