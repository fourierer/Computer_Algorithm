#include<iostream>
#include<vector>

using namespace std

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left]==target?left:-1;
    }
};
