#include<iostream>
#include<vector>

using namespace std;


//超出时间限制，通过26/27个测试用例，官方解法看不太懂
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int result = INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        //枚举上边界
        for(int i=0;i<m;i++)
        {
            //上下界对应的列和数组
            vector<int> sum(n);
            //枚举下边界
            for(int j=i;j<m;j++)
            {
                for(int c=0;c<n;c++)
                    sum[c] += matrix[j][c];//更新每列的元素和
                //计算当前上下边界对应的列和数组中满足条件的result
                for(int start = 0;start<n;start++)
                    for(int end = start;end<n;end++)
                    {
                        int S = accumulate(sum.begin()+start, sum.begin()+end+1, 0);//从索引start开始一直加到end，必须要加1才会包含end
                        if(S<=k)
                            result = max(S,result);
                    }
            }
        }
        return result;
    }
};

