#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end());
        //第一步：动态规划找出最大子集的长度以及最大子集中的最大数
        //dp[i]表示以nums[i]为结尾的最长整除子序列的长度
        vector<int> dp(size,1);
        int M = 1;
        int M_val = nums[0];
        for(int i=0;i<size;i++)
            for(int j=0;j<i;j++)
                if(nums[i]%nums[j]==0)
                {
                    dp[i] = max(dp[j]+1, dp[i]);
                    if(M<dp[i])
                    {
                        M = dp[i];
                        M_val = nums[i];
                    }
                }
        
        //第二步：根据获取的最大长度和最大值回溯子集
        vector<int> result;
        if(M==1)
        {
            result.push_back(nums[0]);
            return result;
        }

        for(int i = size-1;i>=0&&M>0;i--)
        {
            if(dp[i]==M&&M_val%nums[i]==0)
            {
                result.push_back(nums[i]);
                M_val = nums[i];
                M--;
            }
        }
        return result;
    }
};

