#include<iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=0;i<32&&n>0;i++)
        {
            uint32_t tmp = n & 1;//获取n最右边一位
            result = result | tmp<<(31 - i);//将最后一位左移31-i位，即移到反装的位置，随后和result做或运算
            n >>= 1;//n右移一位
        }
        return result;
    }
};

