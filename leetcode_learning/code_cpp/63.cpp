#include<iostream>
#include<vector>

using namespace std;

//dp[i][j]表示从(0,0)到(i,j)的路径数
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,0));
//         //边界条件,如果其中有一个障碍，则后续路径数均为0
//         for(int i=0;i<m;i++)
//         {
//             if(obstacleGrid[i][0]==0)
//                 dp[i][0] = 1;
//             else
//                 break;
//         }
//         for(int j=0;j<n;j++)
//         {
//             if(obstacleGrid[0][j]==0)
//                 dp[0][j] = 1;
//             else
//                 break;
//         }

//         for(int i=1;i<m;i++)
//             for(int j=1;j<n;j++)
//             {
//                 if(obstacleGrid[i][j]==1)
//                     dp[i][j] = 0;
//                 else
//                 {
//                     dp[i][j] = dp[i-1][j] + dp[i][j-1];
//                 }
//             }
        
//         return dp[m-1][n-1];
//     }
// };


//递推只涉及到相邻两行或两列的状态，可以使用滚动数组优化
//dp_row表示dp每一行的状态
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //vector<vector<int>> dp(m, vector<int>(n,0));
        vector<int> dp_row(n,0);
        dp_row[0] = (obstacleGrid[0][0]==0);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                    dp_row[j] = 0;
                if(j>0&&obstacleGrid[i][j]==0)
                {
                    dp_row[j] += dp_row[j-1];
                }
            }
        
        return dp_row[n-1];
    }
};