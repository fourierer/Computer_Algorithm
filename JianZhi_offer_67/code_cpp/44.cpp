#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.length();
        stack<string> stk;
        int start = 0;//记录当前单词开始位置
        int end = 0;//记录当前单词结束位置

        for(int i=0;i<len;i++)
        {
            if(str[i]==' ')
            {
                end = i-1;
                string word = str.substr(start, end-start+1);
                stk.push(word);
                start = i+1;
            }
        }
        stk.push(str.substr(start, len-start));//最后一个空格到结尾的单词入栈
        
        //栈中单词放置到char*中
        char* str_return = new char[len];
        int position = 0;
        while(!stk.empty())
        {
            string str_tmp = stk.top();
            stk.pop();
            int tmp_len = str_tmp.length();
            //cout<<tmp_len<<endl;
            for(int i=0;i<tmp_len;i++)
            {
                str_return[i+position] = str_tmp[i];
            }
            if(tmp_len+position<len)
                str_return[tmp_len+position] = ' ';//防止最后一个单词的后面还有空格
            position += (tmp_len+1);       
        }
        string str_return1 = str_return;//char*转string
        return str_return1;
    }
};

int main()
{
    Solution s;
    string str = "student. a am I";
    string str_return1 = s.ReverseSentence(str);
    cout<<str_return1.size()<<endl;
    cout<<str_return1<<endl;
    return 0;
}

