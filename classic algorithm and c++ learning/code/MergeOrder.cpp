#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void MergeOrder(vector<int>& v)
    {
        vector<int> tool_v(v.size(),0);
        solve(v, 0, v.size()-1, tool_v);
    }
private:
    void solve(vector<int>& a, int left, int right, vector<int>& b)
    {
        if(right>left)
        {
            int mid = (left+right)/2;
            solve(a, left, mid, b);
            solve(a, mid+1, right, b);
            merge(a, left, mid, right, b);
        }
    }
    void merge(vector<int>& a, int left, int mid, int right, vector<int>& b)
    {
        int i = left;
        int j = mid+1;
        int k = 0;
        while(i<=mid&&j<=right)
        {
            if(a[i]<a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }
        while(i<=mid)
            b[k++] = a[i++];
        while(j<=right)
            b[k++] = a[j++];
        for(int i=0;i<k;i++)
            a[left+i] = b[i];
    }
};

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    Solution s;
    s.MergeOrder(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}

//其中用到了一个工具数组tool_v，实际上这个数组只在二路归并的时候起到作用，所以可以简化如下：
class Solution
{
public:
    void MergeOrder(vector<int>& v)
    {
        solve(v, 0, v.size()-1);
    }
private:
    void solve(vector<int>& a, int left, int right)
    {
        if(right>left)
        {
            int mid = (left+right)/2;
            solve(a, left, mid);
            solve(a, mid+1, right);
            merge(a, left, mid, right);
        }
    }
    void merge(vector<int>& a, int left, int mid, int right)
    {
        int i = left;
        int j = mid+1;
        int k = 0;
        //在merge函数中定义工具数组b
        vector<int> b(right-left+1);
        while(i<=mid&&j<=right)
        {
            if(a[i]<a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }
        while(i<=mid)
            b[k++] = a[i++];
        while(j<=right)
            b[k++] = a[j++];
        for(int i=0;i<k;i++)
            a[left+i] = b[i];
    }
};
