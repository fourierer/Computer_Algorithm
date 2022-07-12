/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;

//方法一：直接模拟
// class Solution {
// public:
//     int oddCells(int m, int n, vector<vector<int>>& indices) {
//         int res = 0;
//         vector<vector<int>> matrix(m, vector<int>(n));
//         for (int I=0;I<indices.size();I++) {
//             vector<int> index = indices[I];
//             for (int i = 0; i < n; i++) {
//                 matrix[index[0]][i]++;
//             }
//             for (int i = 0; i < m; i++) {
//                 matrix[i][index[1]]++;
//             }
//         }
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] & 1) {
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// };


//方法二
//使用两个数组记录每一行和每一列增加的次数，如rows[i]表示第i行增加的次数
// class Solution {
// public:
//     int oddCells(int m, int n, vector<vector<int>>& indices) {
//         int result = 0;
//         vector<int> rows(m);
//         vector<int> cols(n);
//         for(int i=0;i<indices.size();i++)
//         {
//             vector<int> index = indices[i];
//             rows[index[0]]++;
//             cols[index[1]]++;
//         }
//         //遍历整个矩阵
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if((rows[i]+cols[j])%2==1)
//                     result++;
//             }
//         }
//         return result;
//     }
// };


//方法三
//进一步考虑数组rows和cols，最终矩阵matrix[i][j]为奇数的充分必要条件是rows[i]
//和cols[j]中必定一个为奇数一个为偶数。
//假设rows数组中有oddx个奇数，cols数组有oddy个奇数，
//则rows[i]为奇数的那些行对应的列为偶数情况下，才可以使得matrix[i][j]为奇数，即有oddx*(n-oddy)个奇数；
//同理，则rows[i]为偶数的那些行对应的列为奇数情况下，才可以使得matrix[i][j]为奇数，即有oddy*(m-oddx)个奇数；
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int result = 0;
        vector<int> rows(m);
        vector<int> cols(n);
        for(int i=0;i<indices.size();i++)
        {
            vector<int> index = indices[i];
            rows[index[0]]++;
            cols[index[1]]++;
        }
        //计算oddx和oddy
        int oddx = 0;
        int oddy = 0;
        for(int i=0;i<m;i++)
        {
            if(rows[i]%2==1)
                oddx++;
        }
        for(int i=0;i<n;i++)
        {
            if(cols[i]%2==1)
                oddy++;
        }

        return oddx*(n-oddy)+oddy*(m-oddx);
    }
};

// @lc code=end

