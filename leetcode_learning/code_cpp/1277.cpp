#include<iostream>
#include<vector>

using namespace std;

//dp[i][j]表示以(i,j)为右下角的正方形的最大边长，同时dp[i][j]=x也表示以(i,j)为右下角的正方形的数目为x，即变成为1，2，...，x的正方形各一个
//dp[i][j]=min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
//最终结果是所有dp[i][j]之和
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int result = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                    dp[i][j] = matrix[i][j];
                else if(matrix[i][j]==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                
                result += dp[i][j];
            }
        }
        return result;
    }
};
