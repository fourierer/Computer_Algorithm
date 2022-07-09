class Solution {
public:
    void push(int value) {
        s.push(value);
        if(s_min.empty())
            s_min.push(value);
        else if(value<=s_min.top())
            s_min.push(value);
    }
    void pop() {
        if(s.top()==s_min.top())
            s_min.pop();
        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return s_min.top();
    }

private:
    stack<int> s;
    stack<int> s_min;
};
