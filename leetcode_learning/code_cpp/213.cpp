#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int k = nums.size();
        if (k == 0)
        {
            return 0;
        }
        if (k==1)
        {
            return nums[0];
        }
        if(k==2)
            return max(nums[0], nums[1]);
        vector<int> v1(nums.begin(),nums.begin() + k-1);
        vector<int> v2(nums.begin()+1,nums.begin() + k);
        int vv1 = robp(v1);
        int vv2 = robp(v2);
        return max(vv1,vv2);
    }
private:
    int robp(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0], nums[1]);
        vector<int> dp(nums.size());
        dp[0] = max(0,nums[0]);
        dp[1] = max(dp[0], nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};