#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void QuickSortOrder(vector<int>& v)
    {
        solve(v, 0, v.size()-1);
    }
private:
    void solve(vector<int>& a, int start, int end)
    {
        if(start>=end)
            return;
        
        int i = start;
        int j = end;
        int pivot = a[i];

        while(i<j)
        {
            while(a[j]>pivot&&j>i)
                j--;
            swap(a[i], a[j]);

            while(a[i]<pivot&&i<j)
                i++;
            swap(a[i], a[j]);
        }
        solve(a, start, i-1);
        solve(a, j+1, end);
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
    s.QuickSortOrder(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}


