#include<iostream>

using namespace std;


class Solution {
public:
    int arrangeCoins(int n) {
        long cur_sum = 0;//使用long防止cur_sum溢出int
        for(int i=1; i<=n; i++)
        {
            cur_sum += i;
            if(cur_sum > n)
                return i-1;
            else if(cur_sum==n)
                return i;
        }
        return 0;//为了编译通过
    }
};
