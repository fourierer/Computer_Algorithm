#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size==0)
            return 0;
        int i = 0;
        for(int j=1;j<size;j++)
        {
            if(nums[j]!=nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
        
        //如果要求返回前i个元素的数组，可以添加下面的代码
        // for(int index = i+1;index<size;index++)
        // {
        //     nums.pop_back();
        // }
        // return nums;
    }
};