#include<iostream>
#include<string>

using namespace std;

//拆分字符串求解，如"123"可以看成1*10^2+2*10^1+3*10^0
//两个字符串相乘，分别拆分多个数相加的的情形，然后根据10的次数进行对应数组位置值的计算
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> result(m+n, 0);
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int exp = m-1-i+n-1-j;//10的次数
                result[exp] += a*b;//按照10的次数将乘积加到数组对应的位置上
            }
        }
        //扫描数组，计算每位的进位数
        for(int index=0;index<m+n-1;index++)
        {
            int flag = result[index]/10;
            result[index] %= 10;
            result[index+1] += flag;
        }
        //整合字符串
        string str = "";
        bool zero = false;//从后往前，遇到一个不为零的则将zero设置为true
        for(int index=m+n-1;index>=0;index--)
        {
            if(result[index]!=0)
                zero = true;
            if(zero)
                str += to_string(result[index]);
            //如果遍历到result第一位仍然是0，则最终结果为0
            if(index==0&&zero==false)
                str = "0";
        }
        return str;
    }
};

