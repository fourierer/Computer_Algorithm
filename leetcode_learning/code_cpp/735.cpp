#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        stk.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++)
        {
            if(stk.empty())
            {
                stk.push(asteroids[i]);
            }
            else
            {
                if((stk.top()*asteroids[i]>0)||(stk.top()<0&&asteroids[i]>0))
                    //当前行星和栈中行星同方向 或者 栈中行星往左，当前行星往右
                    stk.push(asteroids[i]);
                else//当前行星和栈中行星不同向
                {
                    if(abs(stk.top())==abs(asteroids[i]))
                    {    
                        stk.pop();
                        continue;
                    }
                    else if(abs(stk.top())>abs(asteroids[i]))
                        continue;
                    else
                    {
                        stk.pop();
                        i = i-1;//保持i不变，执行结束i会自动加1
                    }
                }
            }
        }

        //将栈转换为数组
        vector<int> result;
        while(!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(),result.end());//反转数组
        return result;
    }
};