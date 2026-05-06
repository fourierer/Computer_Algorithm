#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //转置
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                int tem=matrix[j][i];
                matrix[j][i]=matrix[i][j];
                matrix[i][j]=tem;
            }
        }
        //对称
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size()/2;j++){
                int tem=matrix[i][matrix.size()-1-j];
                matrix[i][matrix.size()-1-j]=matrix[i][j];
                matrix[i][j]=tem;
            }
        }   
    }
};

int main()
{
    vector<vector<int> > v;
    vector<vector<int> > v1;
    vector<int> row1,row2,row3,row4;
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);
    row1.push_back(4);
    v.push_back(row1);

    row2.push_back(5);
    row2.push_back(6);
    row2.push_back(7);
    row2.push_back(8);
    v.push_back(row2);

    row3.push_back(9);
    row3.push_back(10);
    row3.push_back(11);
    row3.push_back(12);
    v.push_back(row3);

    row4.push_back(13);
    row4.push_back(14);
    row4.push_back(15);
    row4.push_back(16);
    v.push_back(row4);

    Solution s;
    s.rotate(v);
    for(int i=0;i<v.size();i++)    
    {
        for(int j=0;j<v[0].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}


