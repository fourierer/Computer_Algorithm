class Solution {
public:
    int search(int* A, int n, int target)
    {
        int left = 0;
        int right = n - 1;
        while(left<right)
        {
            int mid = (left + right) / 2;
            if(A[mid]==target)
                return mid;
            //判断左边是否有序
            if(A[left]<A[mid])
            {
                if(A[left]<=target&&target<=A[right])
            }
            else
            {

            }
        }
    }
};