class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        if(length==0)
            return 0;
        int left = 0;
        int right = length - 1;

        while(left<right)
        {
            int mid = (left+right)/2;
            if(rotateArray[mid]<rotateArray[right])
                right = mid;//不能是mid-1
            else if(rotateArray[mid]>rotateArray[right])
                left = mid + 1;
            else
                right--;//此时rotateArray[mid]==rotateArray[right],无法判断最小值在哪边，只能缩小范围
        }
        return rotateArray[left];
    }
};