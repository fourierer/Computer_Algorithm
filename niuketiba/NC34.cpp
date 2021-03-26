#include<iostream>
#include<vector>

using namespace std;

//数学方法，排列组合(不知道为什么会发生浮点错误)
class Solution {
public:
    int uniquePaths(int m, int n) {
        // write code here
        if(n==1)
            return 1;
        if(m==1)
            return 1;
        long count = J(m+n-2)/(J(m-1)*J(n-1));
        return count;
    }
private:
    long J(long n)
    {
        if(n<=1)
            return 1;
        return n*J(n-1);
    }
};


//数学方法，排列组合
class Solution {
public:
    int uniquePaths(int m, int n) {
        // write code here
        if(m==1||n==1)
            return 1;
        long long result = 1;//防止溢出
        int N = m+n-2;
        int M = min(n-1,m-1);
        //cout<<M<<" "<<N<<endl;
        for(int i=1;i<=M;i++)
        {
            result = result*(N-i+1)/i;
        }
        return int(result);
    }
};


//动态规划,dp[i][j]表示从(0,0)元素出发，到(i,j)的路径有多少种
//dp[i][j] = dp[i-1][j]+dp[i][j-1]
class Solution {
public:
    int uniquePaths(int m, int n) {
        // write code here
        vector<vector<int>> dp(m, vector<int>(n,1));//生成m*n全1阵
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m-1][n-1];
    }
};
