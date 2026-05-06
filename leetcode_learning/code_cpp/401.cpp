#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for(int h=0;h<12;h++)
        {
            for(int m=0;m<60;m++)
            {
                if(__builtin_popcount(h)+__builtin_popcount(m)==turnedOn)
                    result.push_back(to_string(h) + ":" + (m<10?"0":"") + to_string(m));
            }
        }
        return result;
    }
};



//__builtin_popcount函数计算某个数二进制表示下1的个数
int main()
{
    int a = 4;
    int cnt = __builtin_popcount(a);
    cout<<cnt<<endl;
    return 0;
}

