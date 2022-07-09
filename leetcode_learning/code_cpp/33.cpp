#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size==0)
            return -1;
        int left = 0;
        int right = size - 1;
        int mid;
        while(left<right)
        {
            int mid = (left+right)/2;
            //左边有序
            if(nums[mid]>nums[left])
            {
                if(nums[left]<=target&&target<=nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            //右边有序
            else
            {
                if(nums[mid+1]<=target&&target<=nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        if(nums[left]==target)
            return left;
        else
            return -1;
    }
};