class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        //如果数组只有一个元素
        if(j==0)
        {
            if(nums[0]==val)
                return 0;
            else
                return j+1;
        }
        while(i<=j)
        {
            //从后往前，寻找第一个不等于val的元素
            while(j>=0&&nums[j]==val)
                j--;
            //需要再判断一次
            if(i>j)
                return j+1;
            if(nums[i]==val)
            {
                swap(nums[i],nums[j]);
                i++;
            }
            else
                i++;
        }
        //此时j所在的位置是最后一个不等于val的值，而i是j的后一位
        return j+1;
        //return i;
    }
};

