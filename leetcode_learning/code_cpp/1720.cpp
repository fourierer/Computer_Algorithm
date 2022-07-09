#include<iostream>
#include<vector>

using namespace std;

//思路：利用异或运算性质
//encoded[i] = arr[i] XOR arr[i+1]
//两边同时异或arr[i]：
//encoded[i] XOR arr[i] = arr[i] XOR arr[i+1] XOR arr[i] = arr[i+1]
//arr[i+1] = encoded[i] XOR arr[i]
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int size = encoded.size();
        vector<int> arr(size+1);
        arr[0] = first;
        for(int i=1;i<size+1;i++)
            arr[i] = arr[i-1]^encoded[i-1];
        return arr;
    }
};

