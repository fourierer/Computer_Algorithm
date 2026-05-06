#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int left = j+1;
                int right = n-1;
                int k = j;
                while(left<=right)
                {
                    int mid = left + (right-left)/2;
                    if(nums[mid]<nums[i]+nums[j])
                    {
                        k = mid;
                        left = mid + 1;
                    }
                    else
                        right = mid - 1;
                }
                count += k-j;//k算，j不算
            }
        return count;
    }
};