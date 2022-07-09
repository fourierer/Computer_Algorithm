#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //创建优先队列，即大顶堆
        priority_queue<int> q;
        for(int i=0;i<stones.size();i++)
            q.push(stones[i]);
        
        //模拟粉碎过程
        while(q.size()>1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if(a>b)
                q.push(a-b);
        }
        return q.size()==1?q.top():0;
    }
};
