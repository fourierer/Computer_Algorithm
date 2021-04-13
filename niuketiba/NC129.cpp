//观察阶乘结果可知，n!末尾0的数量就是看n!中可以拆出多少个5，拆出的2的个数肯定比5多，所以不用考虑2
//5中可以拆出1个5,25可以拆出两个5,125中可以拆出3个5，可以类推出前125个数阶乘中5的个数
//5->1,10->2,15->3,20->4,25->6
//30->7,35->8,40->9,45->10,50->12
//55->13,60->14,65->15,70->16,75->18
//80->19,85->20,90->21,95->22,100->24
//105->25,110->26,115->27,120->28,125->31,...以此类推
//可以发现有代码中的规律
class Solution {
public:
    /**
     * the number of 0
     * @param n long长整型 the number
     * @return long长整型
     */
    long long thenumberof0(long long n) {
        // write code here
        long long count = 0;
        while(n>0)
        {
            n /= 5;
            count += n;
        }
        return count;
    }
};



