//解法一、记录0的个数，重建数组(需要较大内存)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_count = 0;
        vector<int> v;
        //记录0出现的次数
        for(int i=0;i<nums.size();i++)
            zero_count++;
        
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=0)
                v.push_back(nums[i]);
        
        if(zero_count!=0)
            for(int i=0;i<zero_count;i++)
                v.push_back(0);
        
        //将v中的元素赋值回nums
        for(int i=0;i<nums.size();i++)
            nums[i] = v[i];
    }
};

//解法二、记录0的个数，在最后末尾补0，实际上erase这个函数可能会浪费内存
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(vector<int>::iterator it = nums.begin();it!=nums.end();)
            if(*it==0)
            {
                count++;
                nums.erase(it);//删除该元素之后，it自动加1
            }
            else
                it++;
        for(int i=0;i<count;i++)
            nums.push_back(0);
    }
};


//解法三、双指针（官方解法）
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int n = nums.size(), left = 0, right = 0;
        while (right < n)
        {
            if (nums[right])
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

