#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        for(int i=0;i<size;i++)
        {
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
                s.push(stoi(tokens[i]));
            else
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if(tokens[i]=="+")
                    s.push(num2 + num1);
                else if(tokens[i]=="-")
                    s.push(num2 - num1);
                else if(tokens[i]=="*")
                    s.push(num2 * num1);
                else if(tokens[i]=="/")
                    s.push(num2 / num1);
            }
        }
        return s.top();
    }
private:
    stack<int> s;
};

