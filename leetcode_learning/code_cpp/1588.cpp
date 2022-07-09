#include<iostream>
#include<vector>

usign namespace std;


//思路：计算每个元素可以组成多少个奇数长度子数组
//arr[i]左边有left_count=i个元素，右边right_count=n-i-1个元素；
//如果arr[i]在某个奇数长度的子数组中，则arr[i]左右元素个数应当同奇同偶；
//(1)当arr[i]两边的个数都为奇数时，左边可以选择{arr[i-1]},{arr[i-1],arr[i-2],arr[i-3]},...有(left_count+1)/2种选择，右边有(right_count+1)/2种选择；
//(2)当arr[i]两边的个数都为偶数时，左边可以选择{},{arr[i-1],arr[i-2]},...有left_count/2+1种，不选则表示0个，也算偶数所以要加1，右边有right_count/2+1种选择；
//(3)所以arr[i]可以组成(x_odd*y_odd+x_even*y_even)个奇数长度子序列
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        for(int i=0;i<n;i++)
        {
            int left_count = i;
            int right_count = n-i-1;
            int x_odd = (left_count+1)/2;
            int y_odd = (right_count+1)/2;
            int x_even = left_count/2+1;//0也算偶数，所以后面+1
            int y_even = right_count/2+1;
            result += arr[i]*(x_odd*y_odd + x_even*y_even);
        }
        return result;
    }
};
