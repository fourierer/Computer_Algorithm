#include<iostream>
#include<vector>

using namespace std;

//动态规划，类似于leetcode中的打家劫舍问题
//dp[i]表示i索引元素及之前的不相邻子序列最大和
//dp[i] = max{dp[i-1],dp[i-2]+array[i]},当前索引i取或者不取
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算
     * @param n int整型 数组的长度
     * @param array int整型vector 长度为n的数组
     * @return long长整型
     */
    long long subsequence(int n, vector<int>& array) {
        // write code here
        //dp[i]表示i索引元素及之前的不相邻子序列最大和
        vector<long long> dp(n);
        dp[0] = max(0,array[0]);
        dp[1] = max(dp[0],(long long)array[1]);
        for(int i=2;i<=n;i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+array[i]);
        }
        return dp[n-1];
    }
};