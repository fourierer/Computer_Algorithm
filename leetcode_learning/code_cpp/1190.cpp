#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int size = s.size();
        stack<char> stk;
        for(int i=0;i<size;i++)
        {
            if(s[i]!=')')
                stk.push(s[i]);
            else
            {
                string tmp = "";
                while(stk.top()!='(')
                {
                    tmp += stk.top();
                    stk.pop();
                }
                stk.pop();//删除'('
                //此时tmp已经是反转后的结果，不需要再使用reverse
                //reverse(tmp.begin(), tmp.end());
                for(int j=0;j<tmp.size();j++)
                    stk.push(tmp[j]);
            }
        }
        string result = "";
        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

