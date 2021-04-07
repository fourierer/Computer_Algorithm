#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        // write code here
        for(int i=n-1,j=0;i>=0&&j<m;)
        {
            if(mat[i][j]==x)
                return {i,j};
            else if(mat[i][j]<x)
                j++;
            else
                i--;
        }
        return {-1,-1};
    }
};