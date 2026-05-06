//解法一、暴力双循环
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int count = 0;
        for(int i = 0;i<nums.size();i++)
            for(int j=i;j<nums.size();j++)
            {
                int sum = 0;
                for(int index = i;index<=j;index++)
                    sum += nums[index];
                if(sum>=lower&&sum<=upper)
                    count ++;
            }
        return count;
    }
};


//解法二、动态规划（实际上还是暴力双循环，但减少了每一次i,j之间元素相加的次数，即用dp记录之前的和）
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int count = 0;
        long dp = 0;
        for(int i = 0;i<nums.size();i++)
            for(int j=i;j<nums.size();j++)
            {
                if(i==j)
                    dp = nums[i];
                else
                    dp += nums[j];
                if(dp>=lower&&dp<=upper)
                    count ++;
            }
        return count;
    }
};

//前两种方法都AC不了，超过时间限制
//解法三、归并排序
class Solution {
public:
    int countRangeSumRecursive(vector<long>& sum, int lower, int upper, int left, int right) {
        if (left == right)
            return 0;
        else
        {
            int mid = (left + right) / 2;
            int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
            int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
            int ret = n1 + n2;

            // 首先统计下标对的数量（和显著逆序数一样，需要先进行计数，实质上也是一种显著逆序数的计算）
            int i = left;
            int l = mid + 1;
            int r = mid + 1;
            while (i <= mid) {
                while (l <= right && sum[l] - sum[i] < lower) l++;
                while (r <= right && sum[r] - sum[i] <= upper) r++;
                ret += (r - l);
                i++;
            }

            // 随后合并两个排序数组
            vector<int> sorted(right - left + 1);
            int p1 = left, p2 = mid + 1;
            int p = 0;
            while (p1 <= mid || p2 <= right) {
                if (p1 > mid) {
                    sorted[p++] = sum[p2++];
                } else if (p2 > right) {
                    sorted[p++] = sum[p1++];
                } else {
                    if (sum[p1] < sum[p2]) {
                        sorted[p++] = sum[p1++];
                    } else {
                        sorted[p++] = sum[p2++];
                    }
                }
            }
            for (int i = 0; i < sorted.size(); i++) {
                sum[left + i] = sorted[i];
            }
            return ret;
        }
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long s = 0;
        vector<long> sum{0};
        for(auto& v: nums) {
            s += v;
            sum.push_back(s);
        }
        //sum第一个元素为0，后面为前面元素相加的和
        //如输入数组为[-2,5,-1]，则sum为[0,-2,3,2]
        //这里相加之后，后续计算i,j之间的和时，只需要计算sum[j]-sum[i]即可，便于使用归并排序
        return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
    }
};


//解法四、还是归并排序，不过将归并的过程用一个单独的函数表示，
//并且将工具数组tool_v移到归并函数里面，不用一开始就定义工具数组
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long s = 0;
        vector<long> sum{0};
        for(auto& v: nums)
        {
            s += v;
            sum.push_back(s);
        }
        int count = solve(sum, 0, sum.size()-1, lower, upper);
        return count;
    }
private:
    int solve(vector<long>& a, int left, int right, int lower, int upper)
    {
        long cnt = 0;
        int mid = (left+right)/2;
        if(right>left)
        {
            cnt += solve(a, left, mid, lower, upper);
            cnt += solve(a, mid+1, right, lower, upper);
            cnt += merge(a, left, mid, right, lower, upper);
        }
        return cnt;
    }
    
    int merge(vector<long>& a, int left, int mid, int right, int lower, int upper)
    {
        /*
        //开始计数，这段计算代码无法AC，因为无法保证j2要比j1大
        //实际
        int i = left;
        int j1 = mid+1;
        int j2 = right;
        long merge_count = 0;
        while(i<=mid)
        {
            while(a[j1]-a[i]<lower&&j1<=right)
                j1++;
            while(a[j2]-a[i]>upper&&j2>=mid+1)
                j2--;
            merge_count += j2-j1+1;
            i++;
        }
        */
        
        //官方计数代码
        int i = left;
        int l = mid + 1;
        int r = mid + 1;
        long merge_count = 0;
        while (i <= mid)
        {
            while (l <= right && a[l] - a[i] < lower) l++;
            while (r <= right && a[r] - a[i] <= upper) r++;
            merge_count += (r - l);
            i++;
        }
        

        //计数完成再归并排序
        i = left;
        int j = mid+1;
        int k = 0;
        vector<long> tool_a(right-left+1);
        while(i<=mid&&j<=right)
        {
            if(a[i]<a[j])
                tool_a[k++] = a[i++];
            else
                tool_a[k++] = a[j++];
        }
        while(i<=mid)
            tool_a[k++] = a[i++];
        while(j<=right)
            tool_a[k++] = a[j++];
        for(int i = 0;i<k;i++)
            a[left+i] = tool_a[i];
        
        return merge_count;    
    }
};





