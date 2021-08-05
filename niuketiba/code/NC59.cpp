#include<iostream>
#include<vector>

using namespace std;


//dp[i][j]表示从[0,0]->[i,j]的最短路径和
//dp[i][j]=min{dp[i-1][j],dp[i][j-1]} + matrix[i][j]
class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        int sum = 0;
        //给第一行赋值
        for(int i = 0;i<m;i++)
        {
            sum += matrix[i][0];
            dp[i][0] = sum;
        }
        sum = 0;
        //给第一列赋值
        for(int j=0;j<n;j++)
        {
            sum += matrix[0][j];
            dp[0][j] = sum;
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + matrix[i][j];
        return dp[m-1][n-1];
    }
};