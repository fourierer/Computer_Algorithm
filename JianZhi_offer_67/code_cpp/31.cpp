//未完成
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n){ 
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10)
            ones += (n/m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);
         return ones;
     
    }
};