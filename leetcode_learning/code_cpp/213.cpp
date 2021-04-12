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
    int robp(vector<int>& num) {
        int k = num.size();
        if(k==0)
        {
            return 0;
        }
        int curmax = 0;
        int premax = 0;
        //动态规划求解
        for(int i = 0;i<k;i++)
        {
            int temp = curmax;
            curmax = max(premax+num[i],curmax);
            premax = temp;            
        }

        return curmax;
    }
    
};