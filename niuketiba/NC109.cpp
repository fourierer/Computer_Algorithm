#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//递归
class Solution {
public:
    int solve(vector<vector<char> >& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    DFS(i, j, grid.size(), grid[0].size(), grid);
                    count++;
                }
            }
            return count;
    }
private:
    int DFS(int i, int j, int m, int n, vector<vector<char>>& grid)
    {
        if(i<0||j<0||i>m-1||j>n-1||grid[i][j]=='0')
            return 0;
        grid[i][j] = '0';
        DFS(i-1,j,m,n,grid);
        DFS(i+1,j,m,n,grid);
        DFS(i,j-1,m,n,grid);
        DFS(i,j+1,m,n,grid);
        return 0;
    }
};


//非递归(超时)
class Solution {
public:
    int solve(vector<vector<char> >& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    q.push({i,j});
                    count++;
                    zeros(grid,q);
                }
            }
        return count;
    }
private:
    queue<vector<int>> q;
    int zeros(vector<vector<char>>& grid, queue<vector<int>>& q)
    {
        while(!q.empty())
        {
            vector<int> index = q.front();
            q.pop();
            int i = index[0];
            int j = index[1];
            grid[i][j]=='0';
            if(!fit(i-1,j,grid.size(),grid[0].size(),grid))
                q.push({i-1,j});
            if(!fit(i+1,j,grid.size(),grid[0].size(),grid))
                q.push({i+1,j});
            if(!fit(i,j-1,grid.size(),grid[0].size(),grid))
                q.push({i,j-1});
            if(!fit(i,j+1,grid.size(),grid[0].size(),grid))
                q.push({i,j+1});
        }
        return 0;
    }
    bool fit(int i, int j, int m, int n, vector<vector<char>> grid)
    {
        return (i<0||j<0||i>m-1||j>n-1||grid[i][j]=='0');
    }
};


