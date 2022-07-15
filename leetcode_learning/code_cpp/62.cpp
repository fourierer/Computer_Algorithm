#include<iostream>
#include<vector>

using namespace std;

//dp[i][j]表示从(0,0)到(i,j)的路径数
//dp[i][j] = dp[i-1][j]+dp[i][j-1]
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++)
            dp[i][0] = 1;
        for(int j=0;j<n;j++)
            dp[0][j] = 1;
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};