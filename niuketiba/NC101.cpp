class Solution {
public:
    /**
     * 找缺失数字
     * @param a int整型一维数组 给定的数字串
     * @param aLen int a数组长度
     * @return int整型
     */
    int solve(int* a, int aLen) {
        for(int i=0;i<aLen-1;i++)
        {
            if(a[i+1]-a[i]!=1)
                return a[i] + 1;
        }
        return a[aLen-1] + 1;
    }
};

