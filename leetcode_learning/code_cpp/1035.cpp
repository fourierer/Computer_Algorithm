#include<iostream>
#include<vector>

using namespace std;

//最长公共子序列长度的解法
//dp[i][j]表示nums1[0]~nums1[i-1]与nums2[0]~nums[j-1]之间不相交的连线个数
//状态转移方程和最长公共子序列一样
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=1;i<m+1;i++)
            for(int j=1;j<n+1;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        return dp[m][n];
    }
};


