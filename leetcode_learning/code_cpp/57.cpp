class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int> > ans;
        bool flag = false;//记录新区间是否已经被插入
        for(int i=0;i<intervals.size();i++)
        {
            vector<int> tmp_v = intervals[i];
            //如果新区间在当前区间的右侧，直接插入当前区间
            if(tmp_v[1]<left)
                ans.push_back(tmp_v);
            //如果新区间在当前区间左侧，需要先判断新区间是否已经插入了，如果不判断，会导致新区间重复插入
            //如果没插入，则插入新区间，且将flag置为true，再插入当前区间即可
            //如果已经插入，直接插入当前区间即可
            else if(tmp_v[0]>right)
            {
                if(!flag)
                {
                    ans.push_back({left,right});
                    flag = true;
                }
                ans.push_back(tmp_v);
            }
            //如果新区间和当前区间有交集，则将新区间更新为和当前区间的并集
            else
            {
                left = min(left,tmp_v[0]);
                right = max(right, tmp_v[1]);
            }
        }
        //最后再判断新区间是否已经插入了，如果还没有插入，则将新区间插到最后一个位置
        if(!flag)
            ans.push_back({left,right});
        return ans;
    }
};