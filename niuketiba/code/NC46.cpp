#include<iostream>
#include<vector>

using namespace std;

//超时，思路应该没问题
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> result;
        //先将数组排序
        sort(nums.begin(),nums.end());
        //mask<(1<<nums.size())，假设nums.size()为4，则mask从0000到1111
        for(int mask=0;mask<(1<<nums.size());mask++)
        {
            vector<int> tmp;
            bool flag = true;
            for(int i=0;i<nums.size();i++)
            {
                //根据mask来确定哪些数添加进当前数组
                if(mask&(1<<i))
                {
                    //如果当前mask中第i位为1,第i-1位为0，并且nums[i]=nums[i-1]，则当前mask确定的数组舍弃
                    if(i>0&&(mask>>(i-1) & 1)==0 && nums[i]==nums[i-1])
                    {
                        flag = false;
                        break;
                    }
                    tmp.push_back(nums[i]);
                }
            }
            if(flag&&EqualTarget(tmp, target))
                result.push_back(tmp);
        }
        return result;
    }
private:
    bool EqualTarget(vector<int> v, int target)
    {
        return accumulate(v.begin(), v.end(), 0)==target;
    }
};
