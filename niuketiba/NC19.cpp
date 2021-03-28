#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxsumofSubarray(vector<int>& arr) {
        // write code here
        int size = arr.size();
        //dp[i]表示以arr[i]为最后一个数字的最长无重复子串的长度
        vector<int> dp(size);
        dp[0] = arr[0];
        for(int i=0;i<size;i++)
        {
            dp[i] = max(dp[i-1] + arr[i], arr[i]);
        }
        //找dp中最大的数
        int M = INT_MIN;
        for(int i=0;i<size;i++)
            M = max(M, dp[i]);
        return M;
    }
};