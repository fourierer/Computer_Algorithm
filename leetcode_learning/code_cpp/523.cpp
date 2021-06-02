#include<iostream>
#include<vector>
#include<map>

using namespace std;

//计算前缀和数组sum，sum[i]表示nums中从nums[0]加到nums[i-1]的和
//则，nums[i]+nums[i+1]+...+nums[j]=sum[j+1]-sum[i]
//使用前缀和，然后双循环遍历，通过93/94个测试案例，超时
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2)
            return false;
        //前缀和数组
        vector<int> sum(n+1, 0);
        sum[0] = 0;
        int s = 0;
        for(int i=1;i<=n;i++)
        {
            s += nums[i-1];
            sum[i] = s;
        }
        //计算连续子数组的和
        for(int i=0;i<n;i++)
            for(int j = i+1;j<n;j++)
            {
                int tmp_sum = sum[j+1] - sum[i];
                if(tmp_sum%k==0)
                    return true;
            }
        return false;
    }
};

//使用前缀和+哈希表存储k的余数
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2)
            return false;
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
        //对sum中每个值计算除以k的余数，并将余数和索引存于map中
        //如果
        map<int, int> mod;
        for(int i=0;i<=n;i++)
        {
            int m = sum[i]%k;
            if(mod.count(m)==1)
            {
                if((i-mod[m])>=2)
                    return true;
            }
            else
                mod[m] = i;
        }
        return false;
    }
};