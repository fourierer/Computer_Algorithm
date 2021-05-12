#include<iostream>
#include<vector>

using namespace std;

//模拟题意,41/42个通过测试用例，超时
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        for(int i=0;i<queries.size();i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            int tmp = 0;
            for(int j = start;j<=end;j++)
                tmp ^= arr[j];
            result.push_back(tmp);
        }
        return result;
    }
};

//Q(left,right)=arr[left]⊕…⊕arr[right]
//=(arr[0]⊕…⊕arr[left−1])⊕(arr[0]⊕…⊕arr[left−1])⊕(arr[left]⊕…⊕arr[right])
//=(arr[0]⊕…⊕arr[left−1])⊕(arr[0]⊕…⊕arr[right])
//=xors[left]⊕xors[right+1]
//只需计算数组xors即可，其中xors[0]=0;xors[i]=arr[0]⊕arr[1]⊕...⊕arr[i-1]
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //构建xors数组
        vector<int> xors(arr.size()+1);
        xors[0] = 0;
        for(int i=1;i<=arr.size();i++)
            xors[i] = xors[i-1]^arr[i-1];
        
        //计算查询结果
        vector<int> result;
        for(int i=0;i<queries.size();i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            result.push_back(xors[start]^xors[end+1]);
        }
        return result;
    }
};

