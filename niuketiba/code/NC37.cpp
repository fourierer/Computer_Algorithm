#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval(): start(0),end(0){}
    Interval(int start, int end): start(start),end(end){}
};

class Solution
{
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> result;
        int size = intervals.size();
        if(size==0)
            return result;
        sort(intervals.begin(),intervals.end(),[&](Interval x, Interval y){
            return x.start<y.start;
        });//按照第一位从小到大排序
        for(int i=0;i<size-1;i++)
        {
            Interval I = intervals[i];
            Interval J = intervals[i+1];
            if(I.end<J.start)
                result.push_back(I);
            else
            {
                int left = min(I.start, J.start);
                int right = max(I.end, J.end);
                intervals[i] = Interval();
                intervals[i+1] = Interval(left, right);
            }
        }
        result.push_back(intervals[size-1]);//处理最后一个区间
        return result;
    }
};


