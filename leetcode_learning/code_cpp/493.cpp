class Solution {
public:
    int reversePairs(vector<int>& v) {
        int count = solve(v,0,v.size()-1);
        return count;
    }
private:
    int solve(vector<int>& a, int left, int right)
    {
        int cnt = 0;
        if(right>left)
        {
            int mid = (right+left)/2;
            cnt += solve(a, left, mid);
            cnt += solve(a, mid+1, right);
            cnt += merge(a, left, mid, right);
        }
        return cnt;
    }
    int merge(vector<int>& a,int left, int mid, int right)
    {
        int i = mid;
        int j = right;
        int merge_count = 0;
        while(i>=left&&j>=mid+1)
        {
            if(long(a[i])>2*long(a[j]))//此处是计算显著逆序数，具有一般性
            {
                merge_count += j-mid;
                i--;
            }
            else
            {
                j--;
            }
        }
        //计数完成，需要归并排序
        i = mid;
        j = right;
        int k=0;
        vector<int> b(right-left+1);
        while(i>=left&&j>=mid+1)
        {
            if(a[i]>a[j])
                b[k++] = a[i--];
            else
                b[k++] = a[j--];
        }
        while(i>=left)
            b[k++] = a[i--];
        while(j>=mid+1)
            b[k++] = a[j--];
        for(int i=0;i<k;i++)
            a[right-i] = b[i];
        
        return merge_count;
    }
};