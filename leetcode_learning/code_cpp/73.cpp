#include<iostream>
#include<vector>

using namespace std;

//使用O(mn)的空间
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(matrix[i][j]==0)
                    index.push_back({i,j});

        for(int i=0;i<index.size();i++)
        {
            vector<int> in = index[i];
            //横排置零
            for(int tmp=0;tmp<col;tmp++)
                matrix[in[0]][tmp] = 0;
            //竖列置零
            for(int tmp=0;tmp<row;tmp++)
                matrix[tmp][in[1]] = 0;
        }
    }
private:
    vector<vector<int>> index;
};


//给出官方一种空间为O(1)的解法，使用第一行和第一列来记录某个元素是否为0;
//这样第一行和第一列的元素会被修改，所以需要再使用两个变量来记录第一行和第一列是否包含0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};


