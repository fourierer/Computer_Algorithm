#include<iostream>
#include<vector>

using namespace std;

//动态规划：
//dp[i]表示以arr[i]为结尾的连乘结果最大值
//dp[i] = max{dp[i-1]*arr[i], arr[i]}
//该思路和求连续子数组的和最大是一样的，通过73/100组用例，因为乘法会因为符号的差异导致漏算，比如[-3,4,-5]，
//dp结果为[-3,4,-5]，但实际上-3和-5的符号可以相互抵消，使得乘积结果更大，所以需要考虑数值的正负。
class Solution {
public:
    double maxProduct(vector<double> arr) {
        int size = arr.size();
        vector<double> dp(size);
        dp[0] = arr[0];
        double M = dp[0];
        for(int i=1;i<size;i++)
        {
            dp[i] = max(dp[i-1]*arr[i], arr[i]);
            M = max(dp[i], M);
        }
        // for(int i=0;i<size;i++)
        // {
        //     cout<<dp[i]<<endl;
        // }
        return M;
    }
};

//沿着乘法的特性看，如果a[i]为负数，那么考虑dp[i]时，dp[i-1]越大dp[i]结果越小，dp[i-1]越小dp[i]结果越大。
//所以只需要同时保存最大值和最小值，就可以写出状态转移方程了。
//a[i] > 0时：
//dp_max[i] = max(a[i], a[i]*dp_max[i-1])
//dp_min[i] = min(a[i], a[i]*dp_minv[i-1])
//a[i] < 0时：
//dp_max[i] = max(a[i], a[i]*dp_min[i-1])
//dp_min[i] = min(a[i], a[i]*dp_max[i-1])
//a[i]=0时，max和min肯定是0。
class Solution {
public:
    double maxProduct(vector<double> arr) {
        int size = arr.size();
        vector<double> dp_max(size);
        vector<double> dp_min(size);
        dp_max[0] = arr[0];
        dp_min[0] = arr[0];
        double M = dp_max[0];
        for(int i=1;i<size;i++)
        {
            if(arr[i]>0)
            {
                dp_max[i] = max(dp_max[i-1]*arr[i], arr[i]);
                dp_min[i] = min(dp_min[i-1]*arr[i], arr[i]);
            }
            else
            {
                dp_max[i] = max(dp_min[i-1]*arr[i], arr[i]);
                dp_min[i] = min(dp_max[i-1]*arr[i], arr[i]);
            }
            M = max(dp_max[i], M);
        }
        // for(int i=0;i<size;i++)
        // {
        //     cout<<dp[i]<<endl;
        // }
        return M;
    }
};

