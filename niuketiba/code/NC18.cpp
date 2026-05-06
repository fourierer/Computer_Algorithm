#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        //先转置
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
            {
                int tmp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = tmp;
            }
        //再根据竖直线中心对称
        for(int i=0;i<n;i++)
            for(int j=0;j<n/2;j++)
            {
                int tmp = mat[i][j];
                mat[i][j] = mat[i][n-1-j];
                mat[i][n-1-j] = tmp;
            }
        return mat;
    }
};