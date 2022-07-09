#include<iostream>
#include<vector>

using namespace std;

//dp[i]表示以nums[i]结尾的最长上升子序列的长度，cnt[i]表示以nums[i]结尾的最长上升子序列的个数；
//dp的递推为：dp[i] = max(dp[j]+1)，其中0<=j<i且nums[j]<nums[i]；
//对于cnt[i]，其等于所有满足dp[j]+1=dp[i]的cnt[j]之和，可以在计算dp[i]的同时统计cnt[i]的值；
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int ans = 0;
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];//重置计数
                    }
                    else if(dp[j]+1==dp[i])
                        cnt[i] += cnt[j];
                }
            }
            if(dp[i]>maxLen)
            {
                maxLen = dp[i];
                ans = cnt[i];//重置计数
            }
            else if(dp[i]==maxLen)
                ans += cnt[i];
        }
        return ans;
    }
};