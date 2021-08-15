#include<iostream>
#include<vector>

using namespace std;

//dp[i][j][k]表示移动i次后位置在(j,k)的路径数
//边界：dp[0][startRow][startColumn]=0,dp[0][j][k]=1,j!=startRow,k!=startColumn
//假设从(j,k)->(j',k'):
//(1)如果(j',k')未出界，则dp[i+1][j'][k'] += dp[i][j][k];
//(2)如果(j',k')出界，则result += dp[i][j][k]
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int result = 0;
        int MOD = 1000000007;
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m, vector<int>(n)));
        //边界
        dp[0][startRow][startColumn] = 1;
        for(int i=0;i<maxMove;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<n;k++)
                {
                    for(auto dir:direction)
                    {
                        int j1 = j+dir[0];
                        int k1 = k+dir[1];
                        if(j1>=0&&j1<m&&k1>=0&&k1<n)
                            dp[i+1][j1][k1] = (dp[i+1][j1][k1] + dp[i][j][k]) % MOD;
                        else
                            result = (result + dp[i][j][k]) % MOD;
                    }
                }
        return result;
    }
};
