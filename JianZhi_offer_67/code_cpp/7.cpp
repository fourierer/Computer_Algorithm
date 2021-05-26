

class Solution {
public:
    int Fibonacci(int n) {
        int *F = new int[40];
        F[0] = 0;
        F[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            F[i] = F[i-1]+F[i-2];
        }
        return F[n];
    }
};



