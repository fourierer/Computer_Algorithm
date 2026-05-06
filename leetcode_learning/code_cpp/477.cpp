#include<iostream>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        int size = nums.size();
        //统计第i位的汉明距离，已知所有数小于2^30
        //10^9<1000^3<1024^3<2^30
        for(int i=0;i<30;i++)
        {
            int count_c = 0;
            for(int j = 0;j<size;j++)
            {
                if(nums[j]&(1<<i))
                    count_c++;
            }
            result += count_c*(size-count_c);
        }
        return result;
    }
};
