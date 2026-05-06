class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int reverse(int x) {
        // write code here
        long tmp = 0;
        //用一个long型的数表示翻转后的x，可能会溢出int
        long sum = 0;
        while(x!=0)
        {
            tmp = x%10;
            sum = sum*10 + tmp;
            x /=10;
        }
        if(sum>INT_MAX||sum<INT_MIN)
            return 0;
        return sum;
    }
};