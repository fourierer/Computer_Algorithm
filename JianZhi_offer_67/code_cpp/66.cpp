#include<iostream>

using namespace std;

class Solution {
public:
    int count = 0;
    int movingCount(int threshold, int rows, int cols)
    {
        int* pass = new int[rows*cols];
        moving_count(threshold, 0, 0, rows, cols, pass);
        //delete[]pass;
        return count;
    }

private:
    void moving_count(int threshold, int i, int j, int rows, int cols, int* pass)
    {
        int index = i*cols + j;
        if(i<0||j<0||i>=rows||j>=cols||pass[index]==1)
            return;
        if(helper(i,j)<=threshold)
        {
            count++;
            pass[index] = 1;
        }
        else
        {
            //pass[index] = 0;
            return;
        }

        moving_count(threshold, i-1, j, rows, cols, pass);
        moving_count(threshold, i+1, j, rows, cols, pass);
        moving_count(threshold, i, j-1, rows, cols, pass);
        moving_count(threshold, i, j+1, rows, cols, pass);
    }
    int helper(int i, int j)
    {
        int sum = 0;
        sum = sum + i%10;
        sum = sum + j%10;
        while((i = i/10)>0)
            sum = sum + i%10;
        while((j = j/10)>0)
            sum = sum + j%10;
        return sum;
    }
};

int main()
{
    //Solution s;
    //int re=s.movingCount(10,2,100);
    //cout<<re;
    int* pass = new int[10];
    for(int i=0;i<10;i++)
        cout<<pass[i]<<' ';
    cout<<'\n';
    bool* pass2 = new bool[10];
    for(int i=0;i<10;i++)
        cout<<pass2[i]<<' ';
    return 0;
}