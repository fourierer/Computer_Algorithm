#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

/*
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> v;
        int m = nums.size();
        for(int i = 0; i<m; i++)
        {
            for(int j = i + 1; j<m; j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        return v;
    }
};
*/

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        map<int, int> vmap;
        vector<int> v;
        int length = nums.size();
        for(int i = 0; i<length; i++)
        {
            int diff = target - nums[i];
            //if(vmap.find(diff)!=vmap.end())//判断map里面是否有某个key，find函数如果找到就返回对应的迭代器，找不到就返回末尾的迭代器
            if(vmap.count(diff)==1)//判断map里面是否有某个key，由于map中的key不允许重复，因此如果key存在就返回1，不存在就返回0
            {
                cout<<nums[i]<<endl;
                v.push_back(vmap[diff]);
                v.push_back(i);
                return v;
            }
            
            vmap[nums[i]] = i;
        }
        return v;
    }
};


int main()
{
    Solution s;
    vector<int> nums;
    vector<int> v;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    v = s.twoSum(nums, 9);
    cout<<v[0]<<' '<<v[1]<<endl;
    /*
    for(map<int, int>::iterator it=vmap.begin();it!=vmap.end();it++)
        cout<<it->first<<":"<<it->second<<endl;
    */
    return 0;
}

