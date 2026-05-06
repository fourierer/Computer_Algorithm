#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for(int i=1;i<=9;i++)
        {
            //第一个for循环决定第一位数字，假设为4
            int num = i;
            for(int j=i+1;j<=9;j++)
            {
                //第二个for循环遍历以4开头的顺位加一的数字，如45,456,4567,...
                num = num*10 + j;
                if(low<=num&&num<=high)
                    result.push_back(num);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
