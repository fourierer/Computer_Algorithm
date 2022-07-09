class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        int lenth = sequence.size();
        if(lenth==0)
            return false;
        return IsPostOrder(sequence, 0, lenth-1);
    }

private:
    bool IsPostOrder(vector<int> sequence, int start, int end)
    {
        if(start>=end)//这里一定是大于等于，等于对应的是叶子节点，大于对应的是空树
            return true;
        int i = end;//在当前递归中寻找根节点
        while(i>start&&sequence[i-1]>sequence[end])
            i--;//while循环结束，i指向大于根节点部分的第一个元素
        for(int j=i-1;j>=start;j--)//循环判断前一部分是否都小于根节点
            if(sequence[j]>sequence[end])
                return false;
        return IsPostOrder(sequence, start, i-1)&&IsPostOrder(sequence, i, end-1);
    }
};