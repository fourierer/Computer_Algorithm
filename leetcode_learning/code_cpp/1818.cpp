
//思路：
//我们使用sum记录所有的差值和，用maxn记录最大的改变前后的差值，
//这样答案即为sum−maxn。

//官方题解
class Solution {
public:
    static constexpr int mod = 1'000'000'007;

    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rec(nums1);
        sort(rec.begin(), rec.end());
        int sum = 0, maxn = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            //lower_bound函数查找目标中第一个比nums2[i]大的数，如果找不到返回n
            int j = lower_bound(rec.begin(), rec.end(), nums2[i]) - rec.begin();
            //j<n，说明找到了第一个比nums2[i]大的数，计算此时的差值，但不一定是最大差值
            if (j < n) {
                maxn = max(maxn, diff - (rec[j] - nums2[i]));
            }
            //j>0有两个作用
            //(1)j==n，则最接近nums2[i]的数就是rec[j-1]
            //(2)0<j<n，还需要比较下最接近nums2[i]的数是不是rec[j-1]，因为小于nums2[i]的数也可以是最接近nums2[i]的数
            if (j > 0) {
                maxn = max(maxn, diff - (nums2[i] - rec[j - 1]));
            }
        }
        return (sum - maxn + mod) % mod;
    }
};

//个人写法
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rec(nums1);
        sort(rec.begin(), rec.end());
        int sum = 0, maxn = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            //lower_bound函数查找目标中第一个比nums2[i]大的数，如果找不到返回n
            //可二分查找，也可直接遍历（超时）
            int j = search(rec, nums2[i]);
            //没找到比nums2[i]大的数，最接近nums2[i]的数是rec[n-1]
            if(j==n)
                maxn = max(maxn, diff - (nums2[i]-rec[j-1]));
            else if(j==0)
                maxn = max(maxn, diff - (rec[j]-nums2[i]));
            else
                maxn = max(maxn, diff - min(nums2[i]-rec[j-1], rec[j]-nums2[i]));
        }
        return (sum - maxn + mod) % mod;
    }
private:
    int mod = 1'000'000'007;
    //直接遍历可能超时
    int search(vector<int> vec, int target)
    {
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]>target)
                return i;
        }
        return vec.size();
    }
    //二分法找vec数组中第一个大于target的索引，如果没有返回vec.size()，无法AC
    // int search(vector<int> vec, int target)
    // {
    //     int left = 0;
    //     int right = vec.size() - 1;
    //     while(left<right)
    //     {
    //         int mid = (right-left)/2 + left;
    //         if(vec[mid]<=target)
    //             left = mid + 1;
    //         else
    //             right = mid;
    //     }
    //     return right<vec.size()?right:vec.size();
    // }
};
