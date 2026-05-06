//解法一、使用第31题的方法，依次获取下一个排列组成全排列
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(nums);
        int size = fun(nums.size());
        for(int i=0;i<size-1;i++)
            result.push_back(nextPermutation(nums));
        return result;
    }
private:
    //寻找下一个全排列的数组
    vector<int> nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j])
                j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + 1 + i, nums.end());
        return nums;
    }

    int fun(int n)
    {
        if(n<=1)
            return 1;
        return n*fun(n-1);
    }
};


//解法二、官方解法（贼难懂，可以看对应的解释去理解）
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};

