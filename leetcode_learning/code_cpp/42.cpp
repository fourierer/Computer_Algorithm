#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = accumulate(height.begin(), height.end(), 0);//对height数组求和，0是和初始值
        int volume = 0;//总体积
        int high = 1;//当前高度

        //双指针
        int left = 0;
        int right = height.size() - 1;
        while(left<=right)
        {
            while(left<=right&&height[left]<high)
                left++;
            while(left<=right&&height[right]<high)
                right--;
            volume += right - left + 1;
            high++;
        }
        return volume - sum;
    }
};