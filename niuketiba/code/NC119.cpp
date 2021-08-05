#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(input.size()<k)
            return result;
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