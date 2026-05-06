//解法一,
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int length = A.size();
        int i = 0;

        // 递增扫描
        while (i + 1 < length && A[i] < A[i + 1])
            i++;
        // 最高点不能是数组的第一个位置或最后一个位置
        if (i == 0 || i == length - 1)
            return false;

        // 递减扫描
        while (i + 1 < length && A[i] > A[i + 1])
            i++;
        return i == length - 1;
    }
};

//解法二
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int length = A.size();
        int i = 0;
        int count = 0;
        // 递增扫描
        for(int i=0;i<length-1;i++)
            if(A[i]<A[i+1])
                count++;
        //数组不能是递增或者递减
        if (count == 0 || count == length - 1)
            return false;
        // 递减扫描
        for(int i=count;i<length-1;i++)
            if(A[i]>A[i+1])
                count++;
        return count==length-1;
    }
};