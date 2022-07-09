#include<iostream>
#include<string>
#include<map>

using namespace std;

//思路：三维背包问题，第一维度为字符串个数，第二维度为0的个数，第三维度为1的个数
//dp[i][j][k]表示在0容量为j，1容量为k，前k个字符串最多包含的字符串的个数
//则dp[i][j][k]=max{dp[i-1][j][k],dp[i-1][j-zeros][k-ones]+1}
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i=1;i<=size;i++)
        {
            map<int, int> count = count_zero_one(strs[i-1]);
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    if(j<count[0]||k<count[1])
                        dp[i][j][k] = dp[i-1][j][k];
                    else
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-count[0]][k-count[1]]+1);
                }
            }
        }
        return dp[size][m][n];
    }
private:
    map<int, int> count_zero_one(string str)
    {
        map<int, int> count;
        count[0] = 0;
        count[1] = 0;
        for(int i=0;i<str.size();i++)
            count[str[i]-'0']++;
        return count;
    }
};

