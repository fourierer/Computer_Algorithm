#include<iostream>
#include<vector>

using namespace std;

//首先想到用哈希表，时间、空间复杂度都为O(n)
//可以先对数组排序，随后三个一组进行遍历，出现一次的数，一定是三个数的第一个
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i=i+3)
        {
            if((i==nums.size()-1)||(nums[i]<nums[i+1]))
                return nums[i];
        }
        return 0;
    }
};
