class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int size = A.size();
        if(size<3)
            return 0;
        sort(A.begin(),A.end());
        for(int i=size-1;i-2>=0;i--)
            if(A[i]<A[i-1]+A[i-2])
                return A[i] + A[i-1] + A[i-2];
        return 0;
    }
};
