#include<iostream>
#include<string>
#include<stack>

using namespace std;

/*
//以下这种写法不正确，会漏判"([)]"这种案例
class Solution {
public:
    bool isValid(string s)
    {
        if(s.length()==0)
            return true;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]=='(')||(s[i]=='[')||(s[i]=='{'))
                s1.push(s[i]);
            if((s[i]==')')||(s[i]==']')||(s[i]=='}'))
                s2.push(s[i]);
        }
        if(s1.size()!=s2.size())
            return false;
        else
            while(!s1.empty())
            {
                char s1_ele = s1.top();
                char s2_ele = s2.top();
                if((s1_ele=='(')&&(s2_ele!=')'))
                    return false;
                if((s1_ele=='[')&&(s2_ele!=']'))
                    return false;
                if((s1_ele=='{')&&(s2_ele!='}'))
                    return false;
                s1.pop();
                s2.pop();
            }
            return true;
    }
private:
    stack<char> s1;
    stack<char> s2;
};
*/

//下面代码还是会段溢出，比如"()))"
class Solution {
public:
    bool isValid(string s)
    {
        if(s.length()==0)
            return true;
        if((s.length()%2==1))
            return false;//不加会发生sk溢出，比如"())"
        if((s[0]==')')||(s[0]==']')||(s[0]=='}'))
            return false;
        //cout<<"run here"<<endl;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]=='(')||(s[i]=='[')||(s[i]=='{'))
                sk.push(s[i]);
            else
            {
                // cout<<sk.top()<<endl;
                // cout<<s[i]<<endl;
                if((sk.top()=='(')&&(s[i]!=')'))
                    return false;
                else if((sk.top()=='[')&&(s[i]!=']'))
                    return false;
                else if((sk.top()=='{')&&(s[i]!='}'))
                    return false;
                else
                    sk.pop();
            }
        }
        if(sk.empty())
            return true;
        else
            return false;
    }
private:
    stack<char> sk;
};


class Solution {
public:
    bool isValid(string s) {
        int l = s.length();
        stack<char> st;
        for(int i=0;i<l;i++)
        {
        	if(s[i] == '(')
        		st.push(')');
        	else if(s[i] == '[')
        		st.push(']');
        	else if(s[i] == '{')
        		st.push('}');
        	else if(st.empty())
        		return false;
        	else if(st.top() != s[i])
        		return false;
        	else
        		st.pop();
		}
		return st.empty();
    }
};


int main()
{
    Solution s;
    string str = "()))";
    cout<<s.isValid(str)<<endl;
    return 0;
}
