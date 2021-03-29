#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findKth(vector<int> v, int n, int k) {
        // write code here
        int result = solve(v, 0, v.size()-1, k);
        return result;
    }
private:
    int solve(vector<int>& a, int start, int end, int k)
    {
        int mid = divide(a, start, end);
        int length_of_right = end - mid;
        if(length_of_right==k-1)
            return a[mid];
        else if(length_of_right>k-1)
            return solve(a, mid+1, end, k);
        else
            return solve(a, start, mid-1, k-length_of_right-1);
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
            while(a[j]>=pivot&&j>i)
                j--;
            swap(a[i], a[j]);
            while(a[i]<=pivot&&i<j)
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
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(2);
    Solution s;
    int result = s.findKth(v,5,3);
    cout<<result<<endl;
    return 0;
}