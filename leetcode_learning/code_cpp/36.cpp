#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(9,0));//rows[i][index]表示board第i行数index+1出现的次数
        vector<vector<int>> columns(9, vector<int>(9,0));//columns[j][index]表示board第j行数index+1出现的次数
        //subboxes[i][j][index]表示board(i,j)处的子九宫格中，数index+1出现的次数
        vector<vector<vector<int>>> subboxes(3, vector<vector<int>>(3, vector<int>(9, 0)));
        
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                char c = board[i][j];
                if(c!='.')
                {
                    int index = c - '0' - 1;
                    rows[i][index]++;
                    columns[j][index]++;
                    subboxes[i/3][j/3][index]++;
                    if(rows[i][index]>1||columns[j][index]>1||subboxes[i/3][j/3][index]>1)
                        return false;
                }
            }
        return true;
    }
};
