#include<iostream>
#include<vector>

using namespace std;

//通过174/279
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size==0)
            return false;
        int left = 0;
        int right = size - 1;
        int mid;
        while(left<right)
        {
            mid = (left+right)/2;
            //左边有序，包括等于的情况，这里判断有序的条件少了，比如[1,0,1,1,1]
            if(nums[mid]>=nums[left])
            {
                if(nums[left]<=target&&target<=nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            //右边有序
            else
            {
                if(nums[mid+1]<=target&&target<=nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        if(nums[left]==target)
            return true;
        else
            return false;
    }
};

//在上面的基础之上添加判断左边有序的函数
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size==0)
            return false;
        int left = 0;
        int right = size - 1;
        int mid;
        while(left<right)
        {
            mid = (left+right)/2;
            //左边有序
            bool flag = IsOrder(nums, left, mid);
            //cout<<flag;
            if(flag)
            {
                if(nums[left]<=target&&target<=nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            //右边有序
            else
            {
                if(nums[mid+1]<=target&&target<=nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        if(nums[left]==target)
            return true;
        else
            return false;
    }
private:
    bool IsOrder(vector<int>& nums, int start, int end)
    {
        for(int i=start;i<end;i++)
            if(nums[i+1]<nums[i])
                return false;
        return true;
    }
};