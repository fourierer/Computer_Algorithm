#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> v_map;
        vector<int> result;
        for(int i=0;i<numbers.size();i++)
        {
            int diff = target - numbers[i];
            if(v_map.count(diff)==1)
            {
                result.push_back(v_map[diff]);
                result.push_back(i+1);
                return result;
            }
            else
                v_map[numbers[i]]=i+1;
        }
        return result;
    }
};