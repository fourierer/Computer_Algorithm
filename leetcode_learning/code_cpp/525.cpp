#include<iostream>
#include<vector>
#include<map>

using namespace std;

//首先将数组中的0全部设置为-1，然后和523题类似使用前缀和，连续子数组和为0说明-1和1的数目一样多
//随后使用双循环遍历满足题意的数组长度，求最大值，通过31/564超时
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                nums[i] = -1;
        }
        //for(int i=0;i<n;i++)
            //cout<<nums[i]<<endl;
        //前缀和数组
        vector<int> sum(n+1, 0);
        sum[0] = 0;
        int s = 0;
        for(int i=1;i<=n;i++)
        {
            s += nums[i-1];
            sum[i] = s;
        }
        //for(int i=0;i<=n;i++)
            //cout<<sum[i]<<endl;
        //计算连续子数组的和
        for(int i=0;i<n;i++)
            for(int j = i+1;j<n;j++)
            {
                int tmp_sum = sum[j+1] - sum[i];
                if(tmp_sum==0)
                    result = max(result, j-i+1);
            }
        return result;
    }
};


//使用前缀和+哈希表
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                nums[i] = -1;
        }
        //for(int i=0;i<n;i++)
            //cout<<nums[i]<<endl;
        //前缀和数组
        vector<int> sum(n+1, 0);
        sum[0] = 0;
        int s = 0;
        for(int i=1;i<=n;i++)
        {
            s += nums[i-1];
            sum[i] = s;
        }
        //for(int i=0;i<=n;i++)
            //cout<<sum[i]<<endl;
        //使用哈希表记录前缀和第一次出现的下标
        //如果前缀和相同，则相减的结果一定为0
        map<int, int> value_first;
        for(int i=0;i<=n;i++)
        {
            if(value_first.count(sum[i]))
            {
                result = max(result, i-value_first[sum[i]]);
            }
            else
                value_first[sum[i]] = i;
        }
        return result;
    }
};
