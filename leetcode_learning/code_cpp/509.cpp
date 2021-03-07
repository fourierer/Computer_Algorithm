class Solution {
public:
    int fib(int N) {
        if(N<2)
            return N;
        int pre = 0;
        int cur = 1;
        int sum = 0;
        for(int i=1;i<N;i++)
        {
            sum = pre + cur;
            pre = cur;
            cur = sum;
        }
        return sum;
    }
};