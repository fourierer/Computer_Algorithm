#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//递归写法
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    DFS(grid, i, j, grid.size(), grid[0].size());
                    count++;
                }
            }
            return count;
    }
private:
    int DFS(vector<vector<char>>& grid, int i, int j, int m, int n)
    {
        if(i<0||j<0||i>m-1||j>n-1||grid[i][j]=='0')
            return 0;
        grid[i][j] = '0';//把'1'置'0'
        DFS(grid, i-1, j, m, n);
        DFS(grid, i+1, j, m, n);
        DFS(grid, i, j-1, m, n);
        DFS(grid, i, j+1, m, n);
        return 0;
    }
};


//非递归写法，在leetcode中通过39/48个案例，提示超时
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        queue<vector<int>> q;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    q.push({i,j});
                    count++;
                    zero(grid, q);
                }
            }
        return count;
    }
private:
    int zero(vector<vector<char>>& grid, queue<vector<int>>& q)
    {
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty())
        {
            vector<int> index = q.front();
            q.pop();
            int i = index[0];
            int j = index[1];
            grid[i][j] = '0';
            if(!fit(i-1,j,m,n,grid))
                q.push({i-1,j});
            if(!fit(i+1,j,m,n,grid))
                q.push({i+1,j});
            if(!fit(i,j-1,m,n,grid))
                q.push({i,j-1});
            if(!fit(i,j+1,m,n,grid))
                q.push({i,j+1});
        }
        return 0;
    }
    bool fit(int i, int j, int m, int n, vector<vector<char>> grid)
    {
        return i<0||j<0||i>m-1||j>n-1||grid[i][j]=='0';
    }
};
