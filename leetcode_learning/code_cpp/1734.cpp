#include<iostream>
#include<vector>

using namespace std;

//思路：和leetcode1720类似，只需求得原数组第一个元素即可解码原数组所有的元素
//total = perm[0]^perm[1]^perm[2]^...^perm[n-1]=1^2^3^...^n,n是奇数,容易计算total的值
//total = perm[0]^(perm[1]^perm[2])^(perm[3]^perm[4])^...^(perm[n-2]^perm[n-1])，由于n是奇数，total可以写成成对异或的写法
//total = perm[0]^encoded[1]^encoded[3]^...^encoded[n-2],encoded是已知的，可以求得perm[0]的值。
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int total = 0;
        for(int i=1;i<=encoded.size()+1;i++)
            total ^= i;
        int result_1_n = calculate(encoded);
        vector<int> result(encoded.size()+1);
        result[0] = total ^ result_1_n;
        for(int i=1;i<result.size();i++)
            result[i] = result[i-1] ^ encoded[i-1];
        return result;
    }
private:
    int calculate(vector<int> encoded)
    {
        int result_1_n = 0;
        for(int i=1;i<encoded.size();i=i+2)
            result_1_n ^= encoded[i];
        return result_1_n;
    }
};

