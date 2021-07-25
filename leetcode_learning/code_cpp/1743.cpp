#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> result(adjacentPairs.size()+1);
        
        //记录每个元素和对应邻接元素
        map<int, vector<int>> mp;
        for(auto v: adjacentPairs)
        {
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }

        //第一个元素
        for(auto [e, adj]: mp)
        {
            if(mp[e].size()==1)
            {
                result[0] = e;
                break;
            }
        }

        //最后一个元素
        // for(auto [e, adj]: mp)
        // {
        //     if(mp[e].size()==1&&e!=result[0])
        //     {
        //         result[adjacentPairs.size()] = e;
        //         break;
        //     }
        // }
        
        //提前确定第二个元素，后续需要用到i-2
        result[1] = mp[result[0]][0];
        for(int i=2;i<adjacentPairs.size()+1;i++)
        {
            vector<int> adj = mp[result[i-1]];
            result[i] = result[i-2]==adj[0]?adj[1]:adj[0];
        }
        return result;
    }
};

