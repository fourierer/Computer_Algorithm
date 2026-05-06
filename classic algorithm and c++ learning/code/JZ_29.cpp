#include<iostream>
#include<vector>

using namespace std;

//只需依次寻找最小的k个数即可
class Solution {
public:
    vector<int> smallestK(vector<int> input, int k) {
        vector<int> result;
        for(int i=0;i<k;i++)
        {
            int index = input.size() - i;
            int ith_min = find_max_k(input, index);
            result.push_back(ith_min);
        }
        return result;
    }
private:
    int find_max_k(vector<int> v, int k)
    {
        int result = solve(v, 0, v.size()-1, k);
        return result;
    }

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
    Solution s;
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    vector<int> result = s.smallestK(v, 4);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl;
    return 0;
}

