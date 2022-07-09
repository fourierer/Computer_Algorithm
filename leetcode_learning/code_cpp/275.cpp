#include<isotream>
#include<vector>

using namespace std;

//可以依次遍历
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        //sort(citations.begin(),citations.end());
        for(int i = citations.size()-1;i>=0;i--)
        {
            if(citations[i]>=h+1)
                h++;
            else
                return h;
        }
        return h;
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int left = 0;
        int right = size - 1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(citations[mid]>=size-mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return size - left;
    }
};

