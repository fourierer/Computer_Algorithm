#include<iostream>

using namespace std;


class Solution {
public:
    int jumpFloorII(int number) {
        if(number<3)
        {
            return number;
        }
        else
        {
            int * F = new int[40];
            F[0] = 0;
            F[1] = 1;
            for(int i=2;i<=number;i++)
            {
                F[i] = 2*F[i-1];
            }
            return F[number];
        }
    }
};