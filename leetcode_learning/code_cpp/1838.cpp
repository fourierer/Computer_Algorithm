class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        //先给数组排序
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long total = 0;
        int left = 0, res = 1;
        for (int right = 1; right < n; ++r)
        {
            //每次移动右边界增加的操作次数
            total += (long long)(nums[right] - nums[right - 1]) * (right - left);
            //如果当前的操作次数超过k，需要改变左边界
            while (total > k)
            {
                //每次移动左边界减少的操作次数
                total -= nums[right] - nums[left];
                ++left;
            }
            //计算当前滑动窗口的长度，更新res
            res = max(res, right - left + 1);
        }
        return res;
    }
};