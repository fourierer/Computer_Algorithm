#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int length = s.size();
        for(int i=0;i<length;i++)
        {
            if(s[i]==' ')
                continue;
            if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/')
            {
                if(cur_operator=='+')
                    stk.push(s[i]-'0');
                else if(cur_operator=='-')
                    stk.push(-(s[i]-'0'));
                else if(cur_operator=='*')
                    stk.top() *= (s[i]-'0');
                else if(cur_operator=='/')
                    stk.top() /= (s[i]-'0');
            }
            if(s[i]=='+')
            {
                cur_operator = '+';
                continue;
            }
            if(s[i]=='-')
            {
                cur_operator = '-';
                continue;
            }
            if(s[i]=='*')
            {
                cur_operator = '*';
                continue;
            }
            if(s[i]=='/')
            {
                cur_operator = '/';
                continue;
            }
        }
        //cout<<cur_operator<<endl;
        int result = 0;
        while(!stk.empty())
        {
            //cout<<stk.top()<<endl;
            result += stk.top();
            stk.pop();
        }
        return result;
    }

private:
    char cur_operator = '+';//初始运算符为+号
    stack<int> stk;
};

int main()
{
    string s = "3/2";
    bool flag = s[1]=='/';
    cout<<flag<<endl;
    return 0;
}
