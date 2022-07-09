#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stk.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> stk;

    void dfs(vector<vector<int>>& graph, int x, int n) {
        if (x == n) {
            ans.push_back(stk);
            return;
        }
        for (auto& y : graph[x])//遍历x能到达的下一个节点
        {
            stk.push_back(y);
            dfs(graph, y, n);
            stk.pop_back();//遍历完再pop出当前节点y
        }
    }
};

