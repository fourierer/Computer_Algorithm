#include<iostream>
#include<vector>

using namespace std;

//差分数组：对于原数组nums[i]，差分数组nums1[i] = nums[i]-nums[i-1];nums1[0] = num[0];
//对差分数组求前缀和数组即得到原数组即：nums[i] = num1[0]+nums1[1]+...+nums[i]
//对于原数组nums某个区间[l,r]添加一个增量inc时，对应的差分数组nums1的改变是：nums1[l]+inc,nums1[r+1]-inc
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n);//初始差分数组元素全0
        for(auto book:bookings)
        {
            int inc = book[2];
            nums[book[0]-1] += inc;//差分数组nums1[l]+inc
            if(book[1]<n)
                nums[book[1]] -= inc;//差分数组nums1[r+1]-inc
        }
        //对差分数组求前缀和得到原数组
        for(int i=1;i<n;i++)
            nums[i] += nums[i-1];
        return nums;
    }
};
