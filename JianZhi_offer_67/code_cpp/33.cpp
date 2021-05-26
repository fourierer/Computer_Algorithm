class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<7)
            return index;//7以下的丑数就是本身
        //p2，p3，p5分别为三个队列的指针，newNum为从队列头选出来的最小数
        int p2 = 0, p3=0, p5=0, newNum = 1;
        vector<int> v;
        v.push_back(newNum);
        while(v.size()<index)
        {
            newNum = min(v[p2]*2, min(v[p3]*3, v[p5]*5));
            if(v[p2]*2==newNum)
                p2++;
            if(v[p3]*3==newNum)
                p3++;
            if(v[p5]*5==newNum)
                p5++;
            v.push_back(newNum);
        }
        return newNum;
    }
};