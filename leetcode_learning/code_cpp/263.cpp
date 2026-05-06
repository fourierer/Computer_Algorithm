//根据丑数的定义，丑数n一定可以写成因式分解的形式n=2^a*3^b*5^c
//只需要不断除以因子2,3,5即可
class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
            return false;
        if(n<=6&&n>0)
            return true;
        while(n%5==0)
            n /= 5;
        while(n%3==0)
            n /= 3;
        while(n%2==0)
            n /= 2;
        if(n==1)
            return true;
        return false;
    }
};