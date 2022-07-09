#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<vector<int>> q;//优先队列以vector第一个元素来排序优先级，leetcode官方使用的是pair<int, int>
        vector<int> result;
        //将前k个元素放入优先队列，包括他们的索引，索引是为了后续删除元素
        for(int i=0;i<k;i++)
            q.push({nums[i], i});
        //取队首元素放入result中
        result.push_back(q.top()[0]);
        //遍历剩余元素
        for(int i=k;i<n;i++)
        {
            q.push({nums[i], i});
            //去除不在滑动窗口中的队首元素
            while(q.top()[1]<=i-k)
                q.pop();
            result.push_back(q.top()[0]);
        }
        return result;
    }
};
