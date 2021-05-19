#include<iostream>
#include<vector>

using namespace std;

//二维前缀和数组，XOR[i+1][j+1]=(matrix[0][0]^matrix[0][1]^...^matrix[0][j])
//                            ^(matrix[1][0]^matrix[1][1]^...^matrix[1][j])
//                            ^...
//                            ^(matrix[i][0]^matrix[i][1]^...^matrix[i][j])
//XOR[i+1][j+1]=XOR[i][j]^XOR[i+1][j]^XOR[i][j+1]^matrix[i][j]
//在上面的递推式中，XOR[i][j]所在区域的元素被异或3次（XOR[i+1][j],XOR[i][j+1]以及XOR[i][j]本身），异或两次结果为0，所以最终的结果相当于只异或了一次
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> XOR(m+1, vector<int>(n+1));
        vector<int> result;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                XOR[i+1][j+1] = XOR[i][j]^XOR[i+1][j]^XOR[i][j+1]^matrix[i][j];
                result.push_back(XOR[i+1][j+1]);
            }
        //从小到大排序，再返回第result.size()-k+1个元素，或者直接从大到小排序返回第k个元素
        //sort(result.begin(), result.end(), greater<int>()); //从大到小排序
        //return result[k-1]
        //sort(result.begin(), result.end());
        //return result[result.size()-k];

        //使用快排函数nth_element
        //应用的范围由它的第一个和第三个参数指定。第二个参数是一个指向第 n 个元素的迭代器。
        //nth_dement() 的执行会导致第 n 个元素被放置在适当的位置。
        //这个范围内，在第 n 个元素之前的元素都小于第 n 个元素，而且它后面的每个元素都会比它大(n个元素两边都未必有序)。
        //算法默认用 < 运算符来生成这个结果，想从大到小排列，增加greater<int>()即可。
        nth_element(result.begin(), result.begin()+k-1, result.end(), greater<int>());
        return result[k-1];
    }
};
