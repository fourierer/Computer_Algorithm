#include<iostream>

using namespace std;

//用两个rand7()构造[1,49]中的随机整数，idx = col + (row - 1)*7；
//取前40个数构造[1,40]中的随机整数(40是为了取10的倍数，实际上取30，20，10也可，不过越小整体耗费的时间复杂度越高)
//idx对10取余数(需要对10进行特殊处理)，可以获得[1,10]的随机整数

class Solution {
public:
    int rand10() {
        int idx = 41;
        int row, col;
        while(idx>40)
        {
            row = rand7();
            col = rand7();
            idx = col + (row-1)*7;
        }
        //idx是[1,40]中的随机整数
        return 1 + (idx-1)%10;//为了将10映射到10，其余数和(idx%10)保持一致
    }
};

//这一题可以推广至两个任意区间的随机整数生成函数的转换，当有负整数的时候加一个正整数到1即可。
