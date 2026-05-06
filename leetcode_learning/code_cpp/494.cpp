#include<iostream>
#include<vector>

using namespace std;

//dp[i][j]表示前i个元素组成j的方案数
//dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j+nums[i-1]]，即nums第i个元素为+或者-
//该递推式中某一项的计算涉及到更后面的项，无法求解
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        int target_max = target;
        for(int i=0;i<size;i++)
            target_max = max(target_max, target+nums[i])
        vector<vector<int>> dp(size+1, vector<int>(target_max+1,0));
        //初始化
        dp[0][0] = 1;
        for(int i=1;i<=size;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(j>nums[i-1])
                    dp[i][j] = dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j+nums[i-1]];
            }
        }
        return dp[size][target];
    }
};


//设sum为所有整数的和，neg为所有负号对应的整数和，则sum-neg为所有正号对应的整数和
//(sum-neg)-neg = target，neg = (sum-target)/2，故neg必须是偶数，否则方案数为0
//问题转化成在数组nums中选取若干元素，使得这些元素之和等于neg，计算选取元素的方案数
//设dp[i][j]表示nums中前i个元素组成若干元素，使得这些元素之和等于j的方案数
//dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i-1]]，nums[i-1]选或者不选
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        int sum = 0;
        for(int i=0;i<size;i++)
            sum += nums[i];
        if(((sum-target)<0)||(((sum-target)%2)!=0))
            return 0;
        int neg = (sum-target)/2;
        vector<vector<int>> dp(size+1, vector<int>(neg+1, 0));
        dp[0][0] = 1;
        for(int i=1;i<=size;i++)
        {
            for(int j=0;j<=neg;j++)
            {
                if(j<nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        return dp[size][neg];
    }
};


