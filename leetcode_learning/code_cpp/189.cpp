#include<iostream>
#include<vector>

using namespace std;

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

//考虑所有情况
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

//前面已经注意到：如果k可以整除n，则环形遍历之后会有元素没有遍历到
//改进思路如下：
//(1)如果k不能整除n，则环形遍历可以遍历完所有元素；
//(2)如果k能整除n，可以将k分解为1和k-1，由于分解两个数一定可以遍历完所有元素，所以分两次移动数组即可
//(3)这种思路也有问题，如6个数，移动3个位置，需要分解为2和1，环形遍历2时，同样有遍历不到的元素，这里直接分解为1+1+1

//直接分解为k个1，提示超时，通过34/37
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==k||k==0)
            return;
        
        for(int i=0;i<k;i++)
        {
            int index = 0;//当前要移动的索引
            int pre = nums[index];
            index = (index + 1) % nums.size();
            while(index)
            {
                int cur = nums[index];
                nums[index] = pre;
                pre = cur;
                index = (index + 1) % nums.size();
            }
            //当index回到0时，此时还有一个数pre没有移动到0
            nums[index] = pre;
        }
    }
};

//直接分解为k-1和1，解答错误，通过33/37
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==k||k==0)
            return;
        //如果可以整除，将k拆成k-1和1
        if(nums.size()%k==0)
        {
            //移动k-1
            int index = 0;//当前要移动的索引
            int pre = nums[index];
            index = (index + k-1) % nums.size();
            while(index)
            {
                int cur = nums[index];
                nums[index] = pre;
                pre = cur;
                index = (index + k-1) % nums.size();
            }
            //当index回到0时，此时还有一个数pre没有移动到0
            nums[index] = pre;

            //移动1
            index = 0;//当前要移动的索引
            pre = nums[index];
            index = (index + 1) % nums.size();
            while(index)
            {
                int cur = nums[index];
                nums[index] = pre;
                pre = cur;
                index = (index + 1) % nums.size();
            }
            //当index回到0时，此时还有一个数pre没有移动到0
            nums[index] = pre;
        }
        //如果不能整除
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


//综上只有考虑因子的解法可以完成该题