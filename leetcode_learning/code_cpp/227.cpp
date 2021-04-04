#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int length = s.size();
        int nums = 0;
        for(int i=0;i<length;i++)
        {
            if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!=' ')//防止字符串中有空格
            {
                nums = nums*10 + int(s[i]-'0');//计算连续数字表示的数
            }
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||i==length-1)//这里一定要添加i==n-1判断条件，因为遍历到最后一个数也需要计算结果
            {
                if(cur_operator=='+')
                    stk.push(nums);
                else if(cur_operator=='-')
                    stk.push(-nums);
                else if(cur_operator=='*')
                    stk.top() *= nums;
                else if(cur_operator=='/')
                    stk.top() /= nums;
                cur_operator = s[i];
                nums = 0;
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
