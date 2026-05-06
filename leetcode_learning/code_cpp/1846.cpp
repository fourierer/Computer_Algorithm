#include<iostream>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int size  = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i=1;i<size;i++)
            arr[i] = min(arr[i], arr[i-1] + 1);
        return arr[size-1];
    }
};
