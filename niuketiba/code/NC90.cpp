#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> getMinStack(vector<vector<int> >& op) {
        vector<int> result;
        for(int i=0;i<op.size();i++)
        {
            if(op[i][0]==1)
                Push(op[i][1]);
            else if(op[i][0]==2)
                Pop();
            else
                result.push_back(getMin());
        }
        return result;
    }
private:
    stack<int> s;
    stack<int> s_min;
    void Push(int x)
    {
        s.push(x);
        if(s_min.empty()||s_min.top()>=x)
            s_min.push(x);
    }
    void Pop()
    {
        if(s.top()==s_min.top())
            s_min.pop();
        s.pop();
    }
    int getMin()
    {
        return s_min.top();
    }
};