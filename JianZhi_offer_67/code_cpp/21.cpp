#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int length = pushV.size();
        stack<int> s;
        int j=0;
        for(int i=0;i<length;i++)
        {
            s.push(pushV[i]);
            while((!s.empty())&&(s.top()==popV[j]))
            /*
            要是没有!s.empty()或者两个条件顺序调换，则当popV[j]已经指到最后一个元素的时候，再进行j++，popv[j]就没有指定的元素了，这样就会溢出，
            所以需要!s.empty()提前结束while，不让运行后面的popV[i]。
            */
            {
                s.pop();
                j++;
            }
        }
        if(s.empty())
            return true;
        return false;
    }
};