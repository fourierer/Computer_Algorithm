#include<iostream>
#include<vector>
#include<map>//hash表的头文件
#include<iterator>//迭代器的头文件

using namespace std;

/*
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int middle = numbers.size()/2;
        sort(numbers.begin(), numbers.end());
        for(int i=0;i+middle<numbers.size();i++)
        {
            if(numbers[i]==numbers[i+middle])
                return numbers[i];
        }
        return 0;
    }
};
*/

class Solution {
public:
    map<int, int> MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> number_map;
        //构造hash表
        for(int i=0;i<numbers.size();i++)
        {
            number_map[numbers[i]] += 1;
        }
        int middle_size = numbers.size()/2;
        int num = 0;
        for(map<int, int>::iterator it=number_map.begin();it!=number_map.end();it++)
        {
            if(middle_size<(it->second))
                num = it->first;
        }
        return number_map;
    }
};


int main()
{
    int len = 10;
    vector<int> v(len);
    for(int i=0;i<len;i++)
    {
        v[i] = i;
    }
    Solution s;
    map<int, int> number_map;
    number_map = s.MoreThanHalfNum_Solution(v);
    for(map<int, int>::iterator it=number_map.begin();it!=number_map.end();it++)
    {
        cout<<it->first<<":"<<it->second<<endl;
    }
    return 0;
}


