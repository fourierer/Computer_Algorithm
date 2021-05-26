//使用双指针i,j分别指向偶数索引位置和奇数索引位置
//如果A[i]为奇，A[j]为偶，则互换位置，i,j同时加2；
//如果A[i]为奇，A[j]为奇，则i不动（需要等待j出现偶数），j加2；
//如果A[i]为偶，A[j]为偶，则j不动（需要等待i出现奇数），i加2；
//如果A[i]为偶，A[j]为奇，则满足条件，j,j同时加2；
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0;
        int j = 1;
        while(i<A.size()&&j<A.size())
        {
            if(A[i]%2==1&&A[j]%2==0)
            {
                swap(A[i], A[j]);
                i += 2;
                j += 2;
            }
            else if(A[i]%2==1&&A[j]%2==1)
                j += 2;
            else if(A[i]%2==0&&A[j]%2==0)
                i += 2;
            else
            {
                i += 2;
                j += 2;
            }
        }
        return A;
    }
};
