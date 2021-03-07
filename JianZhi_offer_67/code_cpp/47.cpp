class Solution {
public:
    int Sum_Solution(int n) {
        int sum = n;
        n&&(sum = sum + Sum_Solution(n-1));//使用短路计算机制，当n=0时，&&发现第一个条件不满足，后面都不会再继续计算
        return sum;
    }
};
