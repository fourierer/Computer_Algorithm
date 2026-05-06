#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int row1 = 0;row1<m;row1++)
        {
            //列和数组
            vector<int> sum_col(n, 0);
            for(int row2 = row1;row2<m;row2++)
            {
                for(int col=0;col<n;col++)
                {
                    sum_col[col] += matrix[row2][col];//每次row2增加，sum_col都会更新
                }
                /*
                cout<<"当前sum_col为:";
                for(int col=0;col<n;col++)
                    cout<<sum_col[col]<<" ";
                cout<<endl;
                */
                //计算区域和
                for(int start=0;start<n;start++)
                {
                    //sum_col中从start到end之间的和
                    int sum_local = 0;
                    for(int end=start;end<n;end++)
                    {
                        sum_local += sum_col[end];
                        if(sum_local==target)
                        {
                            //cout<<row1<<" "<<row2<<" "<<start<<" "<<end<<endl;
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};
