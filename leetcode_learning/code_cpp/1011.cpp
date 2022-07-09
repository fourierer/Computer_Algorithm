#include<iostream>
#include<vector>

using namespace std;

//超出时间限制，77/84个通过测试用例
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int start = Max(weights);//下限是数组中最大元素，假设每个货物都要花一天搬运
        int end = Sum(weights);//上限是数组中元素的和，假设所有货物一天之内搬完
        //遍历查找下限到上限之间承重重量
        for(int i = start;i<=end;i++)
            if(Day(weights, i)<=D)
                return i;
        return end;
    }
private:
    int Max(vector<int> v)
    {
        int result = INT_MIN;
        for(int i=0;i<v.size();i++)
            result = max(result, v[i]);
        return result;
    }
    int Sum(vector<int> v)
    {
        int result = 0;
        for(int i=0;i<v.size();i++)
            result += v[i];
        return result;
    }
    //判断船承重I时，最少需要多少天搬运完
    int Day(vector<int> v, int I)
    {
        int cur = 0;
        int day = 0;
        for(int i=0;i<v.size();i++)
        {
            if(cur+v[i]<=I)
                cur = cur+v[i];
            else
            {
                cur = v[i];//重新开始新的一天
                day++;
            }
        }
        return day+1;
    }
};

//使用二分法查找符合条件的船承重
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int start = Max(weights);//下限是数组中最大元素，假设每个货物都要花一天搬运
        int end = Sum(weights);//上限是数组中元素的和，假设所有货物一天之内搬完
        //二分查找下限到上限之间承重重量
        while(start<end)
        {
            int mid = (start+end)/2;
            if(Day(weights, mid)<=D)
                end = mid;
            else
                start = mid + 1;
        }
        return end;
    }
private:
    int Max(vector<int> v)
    {
        int result = INT_MIN;
        for(int i=0;i<v.size();i++)
            result = max(result, v[i]);
        return result;
    }
    int Sum(vector<int> v)
    {
        int result = 0;
        for(int i=0;i<v.size();i++)
            result += v[i];
        return result;
    }
    //判断船承重I时，最少需要多少天搬运完
    int Day(vector<int> v, int I)
    {
        int cur = 0;
        int day = 0;
        for(int i=0;i<v.size();i++)
        {
            if(cur+v[i]<=I)
                cur = cur+v[i];
            else
            {
                cur = v[i];//重新开始新的一天
                day++;
            }
        }
        return day+1;
    }
};

