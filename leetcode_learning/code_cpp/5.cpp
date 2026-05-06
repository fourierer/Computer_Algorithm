#include<iostream>
#include<string>
#include<vector>

using namespace std;

//dp[i][j]表示字符串s中从i到j是否为回文串，值为0或1
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans = "";
        //k = j-i
        for(int k=0;k<n;k++)
            for(int i=0;i+k<n;i++)
            {
                int j = i+k;
                if(k==0)
                    dp[i][j] = 1;
                else if(k==1)
                    dp[i][j] = (s[i]==s[j]);
                else
                    dp[i][j] = ((s[i]==s[j])&&dp[i+1][j-1]);
                if(dp[i][j]&&k+1>ans.size())
                    ans = s.substr(i,k+1);
            }
        return ans;
    }
};

//注意：不能按照常规双循环遍历i,j，因为递推公式中会涉及i+1，此时dp[i+1][j-1]还没有赋值
//必须将间隔k作为第一个循环
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans = "";
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                ;
            }
        return ans;
    }
};



int main()
{
    string s = "abcdefg";
    string sub_str = s.substr(0,3);//从索引0开始，连续取3个字符
    cout<<sub_str<<endl; // "abc"
    return 0;
}

