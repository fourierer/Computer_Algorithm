#include<iostream>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right)
    {
        bool result = true;
        for(int index=left;index<=right;index++)
        {
            int flag = 0;
            for(auto range: ranges)
            {
                if(index>=range[0]&&index<=range[1])
                    flag=1;
            }
            if(flag==0)
                result = false;
        }
        return result;
    }
};