//基本思路：给定一个长度为n的数字序列[D_0D_1D_2D_3...D_{n-1}][D0D1D2D3…Dn−1]，
//从左往右找到第一个位置i（i>0）使得 D_i>D_{i+1}，并删去 D_i，
//如果不存在，说明整个数字序列单调不降，删去最后一个数字即可，
//思路较简单，但实现起来需要考虑较多的情况，下面的代码较冗杂。
class Solution {
public:
    string removeKdigits(string num, int k) {
        int count = 0;
        //按照基本思路先删除k个数字
        while(count<k)
        {
            int flag = 0;//记录此次遍历是否已经删除了数字
            for(int i=0;i<num.length();i++)
            {
                if((num[i]-'0'>num[i+1]-'0'))
                {
                    num.erase(i,1);
                    count++;
                    flag = 1;
                    break;
                }
            }
            //如果此次遍历还没有删除数字，即整体单调不减，则删除最后一个数字
            if(flag==0)
            {
                num.erase(num.length());
                count++;
            }
        }
        
        //先排除前面的数字为0的情况，如果都为0，则删除之后变为空串
        for(int i=0;i<num.length();)
        {
            //删除到第一个不为0的元素时，返回字符
            if(num[i]!='0')
                break;
            else if(num[i]=='0')
                num.erase(i,1);//删除当前元素之后，i自动加1
        }

        //如果是空串，则返回0
        if(num=="")
            return "0";
        return num;
    }
};

