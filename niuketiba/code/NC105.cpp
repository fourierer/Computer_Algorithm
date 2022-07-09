class Solution {
public:
    int search(vector<int>& nums, int target) {
        // write code here
        int left = 0;
        int right = nums.size()-1;
        int ans = 0;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid]>=target)
            {
                right = mid - 1;
                ans = mid;
            }
            else
                left = mid + 1;
        }
        if(ans>=0&&ans<nums.size()&&nums[ans]==target)
            return ans;
        return -1;
    }
};