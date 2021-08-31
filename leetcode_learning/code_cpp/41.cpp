#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //对于遍历到的数x=nums[i]，如果x属于[1,n]，则交换nums[i]和nums[x-1]
        //如果交换后，nums[i]仍然属于[1,n]，则继续交换，直到nums[i]不属于[1,n]
        //同时防止死循环，应当保证交换的两个数不相等，即nums[x-1]!=nums[i]
        //如果都不符合上述条件，则跳出交换循环，遍历下一个数
        for(int i=0;i<n;i++)
        {
            //int x = nums[i];
            //如果x在[1,n]中且nums[x-1]!=x，则将x换到x-1位置上
            while(nums[i]>0&&nums[i]<=n&&nums[nums[i]-1]!=nums[i])
                swap(nums[nums[i]-1], nums[i]);
        }
        //从头遍历，看那个位置上的值nums[i]!=i+1，则是没有出现的最小正数
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};
