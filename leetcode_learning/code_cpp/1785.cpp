#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        double sum = 0;
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
        sum = fabs(sum - goal);
        return int((sum+limit-1)/limit);//取sum/limit向上取整的数
        //return ceil(temp / (double)limit);//使用ceil函数向上取整
    }
};