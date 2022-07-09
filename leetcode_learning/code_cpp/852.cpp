
//题目保证是一个山脉数组，且长度大于等于3
//遍历
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        for(int i=1;i<size;)
        {
            if(arr[i]>arr[i-1])
                i++;
            else
                return i-1;
        }
        return -1;
    }
};


//二分
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = 0;
        int start = 0;
        int end = arr.size() - 1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(arr[mid]>arr[mid+1])
            {
                ans = mid;//已经记录下mid的位置
                end = mid - 1;
            }
            else
                start = mid + 1;                
        }
        return ans;
    }
};
