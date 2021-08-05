class Solution {
public:
    int search(int* A, int n, int target)
    {
        if(n==0)
            return -1;
        int left = 0;
        int right = n - 1;
        int mid;
        while(left<right)
        {
            int mid = (left + right) / 2;
            //左边有序
            if(A[left]<A[mid])
            {
                if(A[left]<=target&&target<=A[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            //右边有序
            else
            {
                if(A[mid+1]<=target&&target<=A[right])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        if(A[left]==target)
            return left;
        else
            return -1;
    }
};