#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    int clumsy(int N) {
        s.push(N);
        N--;
        int index = 0;
        
        while(N>0)
        {
            if(index%4==0)
                s.top() *= N;
            else if(index%4==1)
                s.top() /= N;
            else if(index%4==2)
                s.push(N);
            else
                s.push(-N);
            index++;
            N--;
        }
        
        //对栈中元素求和
        int sum = 0;
        while(!s.empty())
        {
            sum += s.top();
            s.pop();
        }
        return sum;
}
private:
    stack<int> s;
};