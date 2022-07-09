#include<iostream>
#include<math.h>

using namespace std;

//枚举
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a=0;a<=sqrt(c);a++)
        {
            double b = sqrt(c-a*a);
            if(b==int(b))
                return true;
        }
        return false;
    }
};

//费马平方和定理
//一个非负整数 c 如果能够表示为两个整数的平方和，当且仅当 c 的所有形如 4k + 3 的质因子的幂均为偶数。
class Solution
{
public:
    bool judgeSquareSum(int c){
        for(int base=3;base<=c;base++)
        {
            //判断当前base是否为因子
            if(c%base!=0)
                continue;
            
            //如果是因子，求该因子的幂
            int exp = 0;
            while(c%base==0)
            {
                c /= base;
                exp++;
            }

            //费马平方和定理证明
            if((base%4==3)&&(exp%2!=0))
                return false;
        }
        return true;
    }
};

