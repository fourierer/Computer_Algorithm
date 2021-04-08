#include<iostream>
#include<vector>

using namespace std;

//暴力冒泡
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        int size = arr.size();
        for(int i=0;i<size;i++)
            for(int j=i+1;j<size;j++)
            {
                if(arr[i]>arr[j])
                    swap(arr[i], arr[j]);
            }
        return arr;
    }
private:
    void swap(int& x, int& y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }
};

//归并排序
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        solve(arr, 0, arr.size()-1);
        return arr;
    }
private:
    void solve(vector<int>& a, int left, int right)
    {
        if(left<right)
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


//快速排序
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        solve(arr, 0, arr.size()-1);
        return arr;
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
            while(a[j]>=pivot&&j>i)
                j--;
            swap(a[i],a[j]);
            while(a[i]<=pivot&&i<j)
                i++;
            swap(a[i], a[j]);
        }
        solve(a, start, i-1);
        solve(a, j+1, end);
    }
    void swap(int& x, int& y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }
};
