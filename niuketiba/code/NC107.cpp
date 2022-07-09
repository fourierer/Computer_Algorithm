class Solution {
public:
    /**
     * 寻找最后的山峰
     * @param a int整型一维数组 
     * @param aLen int a数组长度
     * @return int整型
     */
    int solve(int* a, int aLen) {
        // write code here
        if(a[aLen-1]>a[aLen-2])
            return aLen-1;
        for(int i=aLen-2;i>=1;i++)
        {
            if(a[i]>a[i-1]&&a[i]>a[i+1])
                return i;
        }
        if(a[0]>a[1])
            return 0;
        //不会运行，为了通过编译
        return 0;
    }
};

