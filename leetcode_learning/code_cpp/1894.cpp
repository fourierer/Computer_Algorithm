#include<iostream>
#include<vector>

using namespace std

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        //对数组元素求和
        long long total = 0;
        for(int i=0;i<n;i++)
            total += chalk[i];
        
        k = k % total;//避免遍历多次
        
        int index = 0;
        while(true)
        {
            if(k<chalk[index])
                return index;
            else
            {
                k = k - chalk[index];
                index = (index + 1) % n;
            }
        }
    }
};
