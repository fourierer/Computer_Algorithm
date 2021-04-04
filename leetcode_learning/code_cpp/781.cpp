#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> count_map;
        for(int i=0;i<answers.size();i++)
        {
            count_map[answers[i]]++;
        }
        int total_sum = 0;
        for(map<int, int>::iterator it = count_map.begin();it!=count_map.end();it++)
        {
            int x = it->second;//多少只兔子说相同的数字
            int y = it->first;//相同的数字
            total_sum += floor(x,y+1) * (y+1);
        }
        return total_sum;
    }
private:
    int floor(int x, int y)
    {
        //返回x/y向上取整的数
        //加上y-1就可以实现向上取整
        return (x+y-1)/y;
    }
};
