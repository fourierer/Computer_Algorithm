#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int mid;
        while(left<right)
        {
            int mid = (left+right)/2;
            
            if(nums[mid]>nums[right])
                left = mid  + 1;
            else if(nums[mid]<nums[right])
                right = mid;
            else
                right--;
        }
        return nums[left];
    }
};