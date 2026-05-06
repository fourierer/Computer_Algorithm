#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
//解法一、改变sort函数的判断机制，即改写sort函数（注意，如果使用数学公式pow来计算欧式距离会超出时间限制）
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int> > ans;
        //按照数组点与原点的欧式距离进行排序
        sort(points.begin(), points.end(), [&](vector<int> x, vector<int> y)
        {
            return (x[0]*x[0]+x[1]*x[1])<(y[0]*y[0]+y[1]*y[1]);
        });

        /*
        for(int i=0;i<points.size();i++)
            cout<<"["<<points[i][0]<<","<<points[i][1]<<"]"<<endl;
        */

        for(int i=0;i<K;i++)
            ans.push_back(points[i]);

        return ans;
    }
};

//或者这样改写sort函数
bool compare(vector<int>& a,vector<int>& b)
{
    int distance1=a[0]*a[0]+a[1]*a[1];
    int distance2=b[0]*b[0]+b[1]*b[1];
    return distance1<distance2;
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        sort(points.begin(),points.end(),compare);
        for(int i=0;i<K;++i)
        {
            res.push_back(points[i]);
        }
        return res;
    }
};


//解法二、快速排序
//只需依次寻找最近的K个点即可（超出时间限制，因为有一些很nt的例子）
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if(points.size()==K)
            return points;
        vector<vector<int>> result;
        for(int i=0;i<K;i++)
        {
            int index = points.size() - i;
            vector<int> ith_min = find_max_k(points, index);
            result.push_back(ith_min);
        }
        return result;
    }
private:
    vector<int> find_max_k(vector<vector<int>> v, int k)
    {
        vector<int> result = solve(v, 0, v.size()-1, k);
        return result;
    }

    vector<int> solve(vector<vector<int>>& a, int start, int end, int k)
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

    int divide(vector<vector<int>>& a, int start, int end)
    {
        if(start>=end)
            return start;

        int i = start;
        int j = end;
        int pivot = a[start][0]*a[start][0]+a[start][1]*a[start][1];

        while(i<j)
        {
            while(a[j][0]*a[j][0]+a[j][1]*a[j][1]>pivot&&j>i)
                j--;
            swap(a[i], a[j]);//c++自带更换两个vector的函数
            while(a[i][0]*a[i][0]+a[i][1]*a[i][1]<pivot&&i<j)
                i++;
            swap(a[i], a[j]);
        }
        return i;//此时i==j
    }
};


