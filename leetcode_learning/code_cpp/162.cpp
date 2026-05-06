#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right)
        {
            int mid = left+(right-left)/2;
            if(nums[mid]<nums[mid+1])
                left = mid+1;//向上爬坡，高处必有峰值
            else
                right = mid;//向上爬坡，高处必有峰值
        }
        return left;
    }
};
