//注意vector<int>的几种初始化方法;
//(1)vector<int> v(n);//v中有n个元素，默认为0；
//(2)vector<int> v(n,1);//v中有n个元素，全为1；
//(3)vector<int> v{2};//v中有一个元素，为2；
//(4)vector<vector<int>> v;
//v.push_back({i,j});//一次性进一个vector数组{i,j}；
//(5)vector<vector<int>> v(n);//v中有n个二维数组，不过没有赋值，可以使用push_back进行赋值

#include<iostream>
#include<vector>

using namespace std;

//解法一、改写sort函数直接排序
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
            {
                vector<int> tmp_v;
                tmp_v.push_back(i);
                tmp_v.push_back(j);
                result.push_back(tmp_v);
            }
        sort(result.begin(), result.end(), [&](vector<int> x,vector<int> y){
            return abs(x[0]-r0)+abs(x[1]-c0)<abs(y[0]-r0)+abs(y[1]-c0);
        });
        return result;
    }
};


//解法二、桶排序，根据距离分桶
class Solution {
public:
    int dist(int r1, int c1, int r2, int c2) {
        return abs(r1 - r2) + abs(c1 - c2);
    }

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        vector<vector<vector<int>>> bucket(maxDist + 1);

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int d = dist(i, j, r0, c0);
                vector<int> tmp = {i, j};
                bucket[d].push_back(tmp);
            }
        }
        vector<vector<int>> ret;
        for (int i = 0; i <= maxDist; i++) {
            for (auto &it : bucket[i]) {
                ret.push_back(it);
            }
        }
        return ret;
    }
};




int main()
{
    int n = 4;
    vector<int> v(n);
    vector<vector<int>> v2(n);
    v.push_back(3);
    v2[0].push_back(9);
    for(int i=0;i<v2.size();i++)
        cout<<v2[i].size()<<endl;
    return 0;
}


