#include<iostream>
#include<vector>

using namespace std;

//从i向nums[i]连线，可以得到一个有向图；
//由于nums中元素不重复，故有向图由一个环或多个环组成；
//可以遍历nums，使用一个标记数组，找到节点个数最大的环；
// class Solution {
// public:
//     int arrayNesting(vector<int>& nums) {
//         int result = 0;
//         int n = nums.size();
//         vector<int> flag(n);
//         for(int i=0;i<n;i++)
//         {
//             int count_tmp = 0;
//             while(flag[i]==0)
//             {
//                 flag[i] = 1;//i节点已经访问
//                 count_tmp++;//当前环中节点数加1
//                 i = nums[i];//指向下一个节点
//             }
//             result = max(result, count_tmp);
//         }

//         return result;
//     }
// };

//优化空间，对原数组进行原地标记，节省标记数组的空间
//由于数组中的数都是小于n的，可以使用n来标记已经遍历过的节点
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int count_tmp = 0;
            while(nums[i]<n)
            {
                int num = nums[i];//标记之前先保存数值
                nums[i] = n;//标记
                count_tmp++;
                i = num;
            }
            result = max(result, count_tmp);
        }

        return result;
    }
};