#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool compare(int& x, int& y)
{
    return to_string(x)+to_string(y)>to_string(y)+to_string(x);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string result = "";
        int flag = 0;
        for(int i=0;i<nums.size();i++)
        {
            //下面两个if语句是为了防止出现[0,0]或者[1,0,0]等情况
            if(nums[i]!=0)
                flag = 1;
            if(flag==0&&i!=nums.size()-1)
                continue;
            result += to_string(nums[i]);
        }
        return result;
    }
};