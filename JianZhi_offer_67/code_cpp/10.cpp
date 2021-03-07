class Solution {
public:
    int rectCover(int number) {
        if(number<3)
        {
            return number;
        }
        else
        {
            int pre1 = 0;
            int pre2 = 1;
            int cur;
            for(int i = 0;i<number;i++)
            {
                cur = pre1 + pre2;
                pre1 = pre2;
                pre2 = cur;
            }
            return cur;
        }
    }
};