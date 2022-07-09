#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include<set>

using namespace std;

//使用标记数组vector<int> flag来记录次数是否重复
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int length = arr.size();
        vector<int> flag(length,0);//记录每个数出现的次数是否重复
        map<int, int> count_map;
        //遍历原数组，记录每个元素出现的次数
        for(int i=0;i<length;i++)
            count_map[arr[i]]++;
        //遍历次数map，查找是否有数出现的次数相同
        for(map<int,int>::iterator it = count_map.begin();it!=count_map.end();it++)
        {
            if(flag[it->second]==0)
                flag[it->second] = 1;
            else
                return false;
        }
        return true;
    }
};


//使用set来记录次数，再比较set和map的长度，如果相同，说明没有重复
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int length = arr.size();
        map<int, int> count_map;
        set<int> times;
        //遍历原数组，记录每个元素出现的次数
        for(int i=0;i<length;i++)
            count_map[arr[i]]++;
        //遍历次数map，查找是否有数出现的次数相同
        for(map<int,int>::iterator it = count_map.begin();it!=count_map.end();it++)
            times.insert(it->second);
        //如果map和set的长度相同，说明没有重复的元素
        if(times.size()==count_map.size())
            return true;
        return false;
    }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    bool flag = s.uniqueOccurrences(v);
    cout<<endl<<flag<<endl;
    return 0;
}
