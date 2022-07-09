#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(size==1)
            return nums[0];
        int left = 0;
        int right = size - 1;
        int mid;
        while(left<right)
        {
            int mid = (left+right)/2;
            //寻找无序的部分，注意这里判断无序的条件不能写成if(nums[mid]>nums[left]),反例[4,5,6,7,0,1,2]
            if(nums[mid]>nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};