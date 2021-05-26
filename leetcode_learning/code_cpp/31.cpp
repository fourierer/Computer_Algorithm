//个人的写法，只注意到从后往前寻找第一个大于它左边的数（无法AC）
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //从最右边开始寻找第一个数大于它左边的数
        bool flag = false;
        for(int i=nums.size()-1;i>0;i--)
            if(nums[i]>nums[i-1])
            {
                int temp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;
                flag = true;
                break;
            }
        //判断是否有这样的数，如果没有则反转数组
        if(!flag)
        {
            int i = 0;
            int j = nums.size() - 1;
            while(i<j)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
    }
};

//官方写法
//1.首先从后向前查找第一个顺序对 (i,i+1)，满足 a[i] < a[i+1]。这样「较小数」即为 a[i]。此时 [i+1,n) 必然是下降序列。
//2.如果找到了顺序对，那么在区间 [i+1,n) 中从后向前查找第一个元素 jj 满足 a[i] < a[j]。这样「较大数」即为 a[j]。
//3.交换 a[i] 与 a[j]，此时可以证明区间 [i+1,n) 必为降序。我们可以直接使用双指针反转区间 [i+1,n) 使其变为升序，而无需对该区间进行排序。

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
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
    }
};
//reverse(nums.begin() + i + 1, nums.end()) //这行代码必须先加1再加i，否则i等于-1时begin()-i将产生异常

