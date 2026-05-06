//排序+贪心算法
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        //按照所有气球的右侧位置进行排序
        sort(points.begin(),points.end(),[&](vector<int> x, vector<int> y){
            return x[1]<y[1];
        });
        int count = 1;
        int arrow_position = points[0][1];//弓箭初始位置在第一个气球的右侧位置，保证可以引爆第一个气球
        for(int i=0;i<points.size();i++)
        {
            if(points[i][0]>arrow_position)
            {
                arrow_position = points[i][1];
                count++;
            }
        }
        return count;
    }
};

