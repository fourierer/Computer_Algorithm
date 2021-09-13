#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        //遍历作为回旋镖顶点的点
        for(auto p:points)
        {
            map<int, int> m;
            for(auto q:points)
            {
                int dis = (p[0]-q[0])*(p[0]-q[0]) + (p[1]-q[1])*(p[1]-q[1]);
                m[dis]++;
            }
            //对相同距离的点进行排列组合计算回旋镖数量
            for(auto it=m.begin();it!=m.end();it++)
                result += it->second*(it->second-1);
            //或者
            // for(auto [_, x]:m)
            //     result += x*(x-1);
        }
        return result;
    }
};
