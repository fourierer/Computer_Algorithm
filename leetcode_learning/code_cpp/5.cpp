#include<iostream>
#include<string>
#include<vector>

using namespace std;

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

int main()
{
    string s = "abcdefg";
    string sub_str = s.substr(0,3);
    cout<<sub_str<<endl;
    return 0;
}

