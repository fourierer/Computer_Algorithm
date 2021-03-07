//修改sort函数，使用一个map记录arr2中各元素以及对应的索引
//根据这个索引来排序，不在这个map中的，按照值进行升序排序
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> arr2_map;
        for(int i=0;i<arr2.size();i++)
            arr2_map[arr2[i]] = i;
        sort(arr1.begin(),arr1.end(),[&](int x, int y){
            if(arr2_map.count(x))
                return arr2_map.count(y)?arr2_map[x]<arr2_map[y]:true;
            else
                return arr2_map.count(y)?false:x<y;
        });
        return arr1;
    }
};
