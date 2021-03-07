//使用快速排序寻找第k大的数
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int find_max_k(vector<int>& v, int k)
    {
        int result = solve(v, 0, v.size()-1, k);
        return result;
    }
private:
    int solve(vector<int>& a, int start, int end, int k)
    {
        int mid = divide(a, start, end);
        int length_of_right = end - mid + 1;
        if(length_of_right==k)
            return a[mid];
        else if(length_of_right>k)
            return solve(a, mid+1, end, k);
        else
            return solve(a, start, mid-1, k-length_of_right);
    }
    int divide(vector<int>& a, int start, int end)
    {
        if(start>=end)
            return start;

        int i = start;
        int j = end;
        int pivot = a[start];

        while(i<j)
        {
            while(a[j]>pivot&&j>i)
                j--;
            swap(a[i], a[j]);
            while(a[i]<pivot&&i<j)
                i++;
            swap(a[i], a[j]);
        }
        return i;//此时i==j
    }
    void swap(int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
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
    int result = s.find_max_k(v, 2);
    cout<<result<<endl;
    //由于s.find_max函数中的v写的引用，所以会对原数组的顺序产生影响
    //去除引用就会输出原数组
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}

