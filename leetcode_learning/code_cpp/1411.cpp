#include<iostream>
#include<math.h>


class Solution
{
public:
    int numOfWays(int n) {
        long fi0 = 6;
        long fi1 = 6;
        for(int i=2;i<=n;i++)
        {
            long new_fi0 = (2*fi0 + 2*fi1) % mod;//这里必须是long，当n很大时，int无法表示
            long new_fi1 = (2*fi0 + 3*fi1) % mod;
            fi0 = new_fi0;
            fi1 = new_fi1;
        }
        return (fi0+fi1) % mod;   
    }
private:
    int mod = pow(10,9) + 7;
};