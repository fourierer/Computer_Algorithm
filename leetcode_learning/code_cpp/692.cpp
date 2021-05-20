#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<iterator>

using namespace std;

//先用一个map记录各个单词出现的频次，然后使用一个数组result记录共出现了哪些单词，
//在该数组result的基础上，按照字符串从小到大，map中出现频次从大到小排序，
//最后删除result中k个元素之后的那些元素即可。
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> str_count;
        for(int i=0;i<words.size();i++)
            str_count[words[i]]++;
        //result中包含words中出现过的单词
        vector<string> result;
        for(map<string, int>::iterator it = str_count.begin();it!=str_count.end();it++)
            result.push_back(it->first);
        sort(result.begin(), result.end(), [&](string x, string y){
            return str_count[x]==str_count[y]?x<y:str_count[x]>str_count[y];
        });
        //删除result中k个元素以后的元素
        result.erase(result.begin()+k, result.end());
        return result;
    }
};