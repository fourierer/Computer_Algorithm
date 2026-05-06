#include<iostream>

using namespace std;

class Solution {
public:
    int firstBadVersion(long long int n) {
        return search(1,n);
    }
private:
    long long int search(long long int start, long long int end)
    {
        while(start<end)
        {
            long long int mid = (start+end)/2;//也可以使用int类型的，但是使用int mid = left + (right - left) / 2;写法，防止计算时溢出
            if(isBadVersion(mid))
                end = mid;
            else
                start = mid+1;
        }
        return start;
    }
};
