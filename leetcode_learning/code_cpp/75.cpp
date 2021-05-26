#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> count_map;
        int length = nums.size();
        if(length==0)
            return;
        //统计红色0，白色1，蓝色2的个数
        int count_red = 0;
        int count_white = 0;
        int count_blue = 0;

        for(int i=0;i<length;i++)
            count_map[nums[i]]++;
        if(count_map.count(0))
            count_red = count_map[0];
        if(count_map.count(1))
            count_white = count_map[1];
        if(count_map.count(2))
            count_blue = count_map[2];
        
        if(count_red!=0)
            for(int j=0;j<count_red;j++)
                nums[j] = 0;
        if(count_white!=0)
            for(int j=count_red;j<count_red+count_white;j++)
                nums[j] = 1;
        if(count_blue!=0)
            for(int j=count_red+count_white;j<count_red+count_white+count_blue;j++)
                nums[j] = 2;
    }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    s.sortColors(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}

/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
        for (int i = ptr; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
    }
};
*/
