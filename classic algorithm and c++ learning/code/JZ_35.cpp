#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int>& v) {
        vector<int> tool_v(v.size(), 0);
        int count = solve(v,0,v.size()-1,tool_v);
        return count;
    }
private:
    int solve(vector<int>& a, int left, int right, vector<int>& b)
    {
        int cnt = 0;
        if(right>left)
        {
            int mid = (right+left)/2;
            cnt += solve(a, left, mid, b);
            cnt += solve(a, mid+1, right, b);
            cnt += merge(a, left, mid, right, b);
        }
        return cnt;
    }
    int merge(vector<int>& a,int left, int mid, int right, vector<int>& b)
    {
        int i = mid;
        int j = right;
        int merge_count = 0;
        while(i>=left&&j>=mid+1)
        {
            if(a[i]>a[j])//此处是计算显著逆序数，具有一般性
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

int main()
{
    vector<int> v;
    v.push_back(7);
    v.push_back(5);
    v.push_back(6);
    v.push_back(4);
    Solution s;
    int count = s.InversePairs(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    cout<<"count:"<<count<<endl;
    return 0;
}



//和归并排序一样，可以对工具数组进行简化
class Solution {
public:
    int InversePairs(vector<int>& v) {
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
            if(a[i]>a[j])//此处是计算显著逆序数，具有一般性
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