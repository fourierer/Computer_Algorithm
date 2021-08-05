#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        if(matrix.size()==0||matrix[0].size()==0)
            return result;
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while(1)
        {
            //遍历最上面一层
            for(int col = left;col<=right;col++)
                result.push_back(matrix[up][col]);
            up++;
            if(up>down)
                break;
            
            //遍历最右边一层
            for(int row=up;row<=down;row++)
                result.push_back(matrix[row][right]);
            right--;
            if(left>right)
                break;
            
            //遍历最下面一层
            for(int col=right;col>=left;col--)
                result.push_back(matrix[down][col]);
            down--;
            if(up>down)
                break;
            
            //遍历最左边一层
            for(int row=down;row>=up;row--)
                result.push_back(matrix[row][left]);
            left++;
            if(left>right)
                break;
        }
        return result;
    }
};