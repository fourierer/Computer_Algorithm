class Solution { 
public:
    int binarySearchLeft(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1;
                ans = mid;
            }
            else
                left = mid + 1;
        }
        return ans;
    }

    int binarySearchRight(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
                ans = mid;
            }
            else
                left = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        int leftIdx = binarySearchLeft(nums, target);
        //cout<<leftIdx<<endl;
        int rightIdx = binarySearchRight(nums, target)-1;
        //cout<<rightIdx<<endl;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
            return vector<int>{leftIdx, rightIdx};
        return vector<int>{-1, -1};
    }
};
