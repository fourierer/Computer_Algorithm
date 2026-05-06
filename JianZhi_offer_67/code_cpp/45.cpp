class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int numOfZero = 0;
        int numOfInterval = 0;
        int length = numbers.size();
        if(length==0)
            return false;
        sort(numbers.begin(), numbers.end());
        for(int i=0;i<length-1;i++)
        {
            //计算0的数量
            if(numbers[i]==0)
            {
                numOfZero++;
                continue;//这句话不能省，防止后续判断对子会误判0,0为对子
            }
            //判断相邻的是否为对子
            if(numbers[i]==numbers[i+1])
                return false;
            numOfInterval += numbers[i+1]-numbers[i]-1;
        }
        if(numOfZero>=numOfInterval)
            return true;
        return false;
    }
};