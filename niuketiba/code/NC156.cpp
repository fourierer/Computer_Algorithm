#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param arr intvector 
     * @param k int 
     * @return int
     */
    int foundOnceNumber(vector<int>& arr, int k) {
        // write code here
        map<int, int> arr_count;
        for(int i=0;i<arr.size();i++)
            arr_count[arr[i]]++;
        for(map<int, int>::iterator it = arr_count.begin();it!=arr_count.end();it++)
            if(it->second==1)
                return it->first;
        return 0;
    }
};


