//解法一、暴力双循环，依次尝试每个起始位置，看能否走完全程
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++)
        {
            int cur = i;
            int rest = gas[cur] - cost[cur];
            while(rest>=0)
            {
                cur = cur + 1;
                if(cur==gas.size())
                    cur = 0;
                //这两步可以简化为cur = (cur+1)%gas.size();
                if(cur==i)
                    return i;
                rest += gas[cur] - cost[cur];
            }
        }
        return -1;
    }
};


//解法二、官方解法，需要一点数学证明：如果从x出发无法到达y的下一站，则从x,y之间任意一站(包括x,y)出发，都无法到达下一站
//技术路线：首先检查第0个加油站，并试图判断能否环绕一周；如果不能，就从第一个无法到达的加油站开始继续检查；如果检查到第n个加油站还没有找到符合的，就返回-1。
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        while (i < gas.size())
        {
            int rest = 0;
            int cnt = 0;//当前起点能够持续走的加油站个数
            while(cnt < gas.size())
            {
                int j = (i + cnt) % gas.size();
                rest += gas[j] - cost[j];
                if (rest<0)
                    break;
                cnt++;
            }
            if (cnt == gas.size())
                return i;
            else
                i = i + cnt + 1;
        }
        return -1;
    }
};

