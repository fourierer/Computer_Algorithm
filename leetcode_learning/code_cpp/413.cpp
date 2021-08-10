#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), l = 0, ans = 0;
        if(n<=2)
            return 0;
        for(int i = 2; i < n; i++)
        {
            //以最后一个数来遍历
            //如果当前数和前两个数构成等差数列，则当前数也可以和前两个数往前的数构成等差数列，所以l表示当前数增加的等差数列的个数
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
            {
                l++;
                ans += l;
            }
            //如果当前数和前两个数不构成等差数列，则l中断增加，重新寻找可以构成等差数列的序列
            else
                l = 0;
        }
        return ans;
    }
};

