#include<iostream>
#include<string>
#include<vector>

using namespace std;

//暴力求解
class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        int max_len = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<=n;j++)
            {
                string sub_str = A.substr(i,j-i+1);
                //cout<<sub_str<<endl;
                if(IsPalindrome(sub_str)&&sub_str.size()>max_len)
                    max_len = sub_str.size();
            }
        return max_len;
    }
private:
    bool IsPalindrome(string s)
    {
        int n = s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-1-i])
                return false;
        }
        return true;
    }
};


//动态规划，dp[i][j]表示字符串索引从i到j是否是回文串
//边界条件：(1)dp[i][i]=true;(2)dp[i][i+1]=(str[i]==str[i+1])?true:false;
//状态转移方程：dp[i][j]=true if(dp[i+1][j-1]&&str[i]==str[j]),dp[i][j]=false if(str[i]!=str[j])
class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        string ans = "";
        //k = j-i
        for(int k=0;k<n;k++)
            for(int i=0;i+k<n;i++)
            {
                int j = i+k;
                if(k==0)
                    dp[i][j] = true;
                else if(k==1)
                    dp[i][j] = (A[i]==A[j]);
                else
                    dp[i][j] = (A[i]==A[j])&&dp[i+1][j-1];
                if(dp[i][j]&&k+1>ans.size())
                    ans = A.substr(i,k+1);
            }
        return ans.size();
    }
};


int main()
{
    string s = "babcaaccabab";
    Solution solu;
    int result = solu.getLongestPalindrome(s, 12);
    cout<<result<<endl;
    return 0;
}

