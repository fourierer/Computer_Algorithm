//使用贪心算法
//注意到一个事实，对应相邻的两次翻转（行行，列列，行列或者列行），更改翻转顺序，结果不变
//所以先进行行翻转，再进行列翻转。
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        //行变换，将每一行第一个元素不是1的行进行翻转
        for(int i = 0;i<A.size();i++)
        {
            if(A[i][0]==0)
            {
                for(int j=0;j<A[i].size();j++)
                    A[i][j] = 1 - A[i][j];
            }
            else
                continue;
        }

        //列变换，如果某一列的0比1多，则进行列翻转
        for(int j = 0;j<A[0].size();j++)
        {
            int count0 = 0;
            int count1 = 0;
            for(int i = 0;i<A.size();i++)
            {
                if(A[i][j]==0)
                    count0++;
                else
                    count1++;
            }
            if(count0>count1)
            {
                for(int i=0;i<A.size();i++)
                    A[i][j] = 1 - A[i][j];           
            }
            else
                continue;
        }

        //计算分数
        int sum = 0;
        for(int i = 0;i<A.size();i++)
        {
            sum += cal_binary(A[i]);
        }
        return sum;
    }
private:
    int cal_binary(vector<int> v)
    {
        int sum = 0;
        for(int i = 0;i<v.size();i++)
        {
            sum += v[i]*pow(2,v.size()-1-i);
        }
        return sum;
    }
};