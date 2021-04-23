#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        //dp[i]表示以nums[i]为结尾的最长递增子序列
        vector<int> dp(size,1);
        //最长递增子序列的长度
        int M = 1;
        for(int i=0;i<size;i++)
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    M = max(dp[i], M);
                }
            }
        return M;
    }
};

