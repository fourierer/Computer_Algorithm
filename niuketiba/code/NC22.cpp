class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int a = m-1;
        int b = n-1;
        for(int index=m+n-1;index>=0;index--)
        {
            if(a>=0&&b>=0)
            {
                if(A[a]>B[b])
                    A[index] = A[a--];
                else
                    A[index] = B[b--];
            }
            else if(b>=0)
                A[index] = B[b--];
        }
    }
};