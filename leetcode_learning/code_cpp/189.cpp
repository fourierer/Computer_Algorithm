//下面这种写法有bug，比如[-1,-100,3,99],k=2，此时只有-1和3会调换位置，其余的值不变
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==k||k==0)
            return;
        int index = 0;//当前要移动的索引
        int pre = nums[index];
        index = (index + k) % nums.size();
        while(index)
        {
            int cur = nums[index];
            nums[index] = pre;
            pre = cur;
            index = (index + k) % nums.size();     
        }
        //当index回到0时，此时还有一个数pre没有移动到0
        nums[index] = pre;
    }
};

//改进之后发现还是有bug，反例[1,2,3,4,5,6],k=4
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==k||k==0)
            return;
        if(nums.size()%k!=0)
        {
            int index = 0;//当前要移动的索引
            int pre = nums[index];
            index = (index + k) % nums.size();
            while(index)
            {
                int cur = nums[index];
                nums[index] = pre;
                pre = cur;
                index = (index + k) % nums.size();     
            }
            //当index回到0时，此时还有一个数pre没有移动到0
            nums[index] = pre;
        }
        else
        {
            for(int i=0;i<k;i++)
            {
                int index = i;//当前要移动的索引
                int pre = nums[index];
                index = (index + k) % nums.size();
                while(index!=i)
                {
                    int cur = nums[index];
                    nums[index] = pre;
                    pre = cur;
                    index = (index + k) % nums.size();     
                }
                //当index回到0时，此时还有一个数pre没有移动到0
                nums[index] = pre;
            }
        }
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==k||k==0)
            return;

        if(nums.size()%k==0)//如果nums.size()是k的倍数，则需要重复k次跳跃遍历过程
        {
            for(int i=0;i<k;i++)
            {
                int index = i;//当前要移动的索引
                int pre = nums[index];
                index = (index + k) % nums.size();
                while(index!=i)
                {
                    int cur = nums[index];
                    nums[index] = pre;
                    pre = cur;
                    index = (index + k) % nums.size();     
                }
                //当index回到0时，此时还有一个数pre没有移动到0
                nums[index] = pre;
            }
        }
        else if(nums.size()%(nums.size()-k)==0)//如果nums.size()是(nums.size()-k)的倍数，则需要重复(nums.size()-k)次跳跃遍历过程
        {
            for(int i=0;i<nums.size()-k;i++)
            {
                int index = i;//当前要移动的索引
                int pre = nums[index];
                index = (index + k) % nums.size();
                while(index!=i)
                {
                    int cur = nums[index];
                    nums[index] = pre;
                    pre = cur;
                    index = (index + k) % nums.size();     
                }
                //当index回到0时，此时还有一个数pre没有移动到0
                nums[index] = pre;
            }
        }
        else
        {
            int index = 0;//当前要移动的索引
            int pre = nums[index];
            index = (index + k) % nums.size();
            while(index)
            {
                int cur = nums[index];
                nums[index] = pre;
                pre = cur;
                index = (index + k) % nums.size();     
            }
            //当index回到0时，此时还有一个数pre没有移动到0
            nums[index] = pre;
        }
    }
};



