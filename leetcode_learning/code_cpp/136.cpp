#include<iostream>
#include<vector>

using namespace std;

//位运算
//任何数和 0 做异或运算，结果仍然是原来的数，即 a⊕0=a。
//任何数和其自身做异或运算，结果是 0，即 a⊕a=0。
//异或运算满足交换律和结合律，即a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0;i<nums.size();i++)
        {
            result ^= nums[i];
        }
        return result;
    }
};
