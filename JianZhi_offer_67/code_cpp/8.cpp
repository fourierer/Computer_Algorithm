class Solution {
public:
    int jumpFloor(int number) {
        int* F = new int [40];
        F[0] = 0;
        F[1] = 1;
        F[2] = 2;
        for(int i=3;i<=number;i++)
        {
            F[i] = F[i-1] + F[i-2];
        }
        return F[number];
    }
};