#include<iostream>
#include<vector>

using namespace std;

//运行超时
class Solution {
public:
    vector<int> LIS(vector<int>& arr) {
        // write code here
        int size = arr.size();
        //dp[i]表示以第i个元素结尾的最长的递增子序列长度
        vector<int> dp(size, 1);
        int M = 1;//全局最长递增子序列长度
        for(int i=1;i<size;i++)
        {
            for(int j=0;j<i;j++)
                if(arr[i]>arr[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    M = max(M, dp[i]);
                }
        }
        
        vector<int> result;
        //依次计算dp中数值为M,M-1,,M-2,...,1，且在arr最小的数，保证对应的索引值可以依次递减
        int up = dp.size();
        int index = up;
        for(int m = M;m>=1;m--)
        {
            int value = INT_MAX;
            //只在[0,up]中寻找，因为长度为m的为up,当寻找长度为m-1的时候可以限定范围[0,up]
            for(int i=0;i<up;i++)
            {
                if(dp[i]==m&&arr[i]<value)
                {
                    index = i;
                    value = arr[i];
                }
            }
            up = index;
            result.push_back(value);
        }

        reverse(result.begin(),result.end());
        return result;
    }
};
