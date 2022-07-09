#include<iostream>
#include<vector>

using namespace std;

//假设出现一次的两个数分别为a,b
//首先将所有数字进行异或运算，得到a^b的结果x
//在x中二进制遍历，找出现1的那一位，表示a和b的二进制在这一位不一样
//随后根据这一位进行分类，为0的为一组，为1的为一组，则a,b必被分到不同组，并且相同数会被分到同一组
//两组分别异或，得到a,b
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //获取两个出现一次的数的异或结果
        int x = 0;
        for(int i=0;i<nums.size();i++)
            x ^= nums[i];
        //找异或结果中为1的那一位，从低位找起
        int flag = 1;
        while((flag&x)==0)
            flag<<=1;
        int a = 0;
        int b = 0;
        //根据flag进行分组
        for(int i=0;i<nums.size();i++)
        {
            if(flag&nums[i])
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        return vector<int>{a,b};
    }
};

