/*
输入: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
1.先进行排序：首先按照第一个元素从高到低排序，当第一个元素相等时，按照第二个从小到大排序：[[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]；
2.按照排好序的结果再次进行插入排序，按照第二个元素进行插入排序，如第二个元素为2，则插入到索引为2的位置。
输出:
[[7, 0]]
[[7, 0], [7, 1]]
[[7, 0], [6, 1], [7, 1]]
[[5, 0], [7, 0], [6, 1], [7, 1]]
[[5, 0], [7, 0], [5, 2], [6, 1], [7, 1]]
[[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[&](vector<int> x, vector<int> y){
            return x[0]>y[0]||(x[0]==y[0]&&x[1]<y[1]);
        });
        vector<vector<int>> result;
        for(int i=0;i<people.size();i++)
        {
            result.insert(result.begin() + people[i][1],people[i]);
        }
        return result;
    }
};

