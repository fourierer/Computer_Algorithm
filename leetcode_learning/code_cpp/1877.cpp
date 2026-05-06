#include<iostream>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int result = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<size/2;i++)
        {
            result = max(result, nums[i]+nums[size-1-i]);
        }
        return result;
    }
};
