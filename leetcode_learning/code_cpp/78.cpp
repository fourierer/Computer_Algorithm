#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        //mask<(1<<nums.size())，假设nums.size()为4，则mask从0000到1111
        for(int mask=0;mask<(1<<nums.size());mask++)
        {
            vector<int> tmp;
            for(int i=0;i<nums.size();i++)
            {
                //根据mask来确定哪些数添加进当前数组
                if(mask&(1<<i))
                    tmp.push_back(nums[i]);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
