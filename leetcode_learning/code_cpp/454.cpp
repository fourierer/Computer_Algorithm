//解法一、暴力四循环，时间复杂度O(n^4)无法AC
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        int count = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    for(int l=0;l<n;l++)
                        if(A[i]+B[j]+C[k]+D[l]==0)
                            count++;
        return count;
    }
};


//解法二、将AB分为一组存储元素加和的值以及出现的次数，再对CD进行双循环遍历，看是否有负的结果
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        map<int, int> count_AB;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                count_AB[-A[i]-B[j]]++;
        
        int result = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(count_AB.count(C[i]+D[j]))
                    result += count_AB[C[i]+D[j]];
        return result;
    }
};


