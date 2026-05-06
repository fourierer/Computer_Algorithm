#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m==1&&n==1)
            return matrix[0][0]==target;
        for(int i=m-1,j=0;i>=0&&j<n;)
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
            {
                i--;
                continue;
            }
            else
            {
                j++;
                continue;
            }
            return false;
        }
        return false;
    }
};