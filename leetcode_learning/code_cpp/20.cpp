#include<iostream>
#include<string>
#include<stack>
#include<map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        //哈希表
        map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';
        
        // map<char, char> m = {
        //     {')', '('},
        //     {']', '['},
        //     {'}', '{'}};

        int size = s.size();
        // cout<<size<<endl;
        if(size%2==1)
            return false;
        stack<char> stk;
        for(int i=0;i<size;i++)
        {
            if(stk.empty())
                stk.push(s[i]);
            else
            {
                if(m.count(s[i]))
                {
                    if(stk.top()==m[s[i]])
                        stk.pop();
                    else
                        return false;//如果s[i]是右括号且当前栈顶
                                     //元素不是相应的左括号，则返回false
                }
                else
                    stk.push(s[i]);
            }
        }

        return stk.empty();
    }
};