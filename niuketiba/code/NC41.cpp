#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        int size = arr.size();
        map<int, int> arr_count;
        arr_count[arr[0]] = 0;//初始哈希中只有第一个元素
        int ML = 1;//初始最大长度为1
        int i=0;
        int j=1;//j=1是即将要添加的元素
        while(i<=j&&j<size)
        {
            if(arr_count.count(arr[j]))//如果当前哈希中有要添加的元素，那么从i一直删到与要添加的arr[j]不重复为止
            {
                //删除元素
                while(arr[i]!=arr[j])
                {
                    arr_count.erase(arr[i]);
                    i++;
                }
                i++;//删除到重复元素之后要再加1
            }
            //如果当前哈希中没有要添加的元素，那么直接加上arr[j]
            arr_count[arr[j]] = j;
            ML = ML>arr_count.size()?ML:arr_count.size();
            j++;
        }
        return ML;
    }
};