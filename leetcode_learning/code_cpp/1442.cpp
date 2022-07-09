#include<iostream>
#include<vector>
#include<map>

using namespace std;

//考虑前缀和数组XOR
//XOR[0]=0;XOR[i]=arr[0]⊕arr[1]⊕...⊕arr[i-1]
//XOR[j]=arr[0]⊕arr[1]⊕...⊕arr[j-1]
//XOR[k+1]=arr[0]⊕arr[1]⊕...⊕arr[k]
//a=arr[i]⊕...⊕arr[j-1]=XOR[i]⊕XOR[j]
//b=arr[j]⊕...⊕arr[k]=XOR[j]⊕XOR[k+1]
//若a=b，即XOR[i]⊕XOR[j]=XOR[j]⊕XOR[k+1]，即XOR[i]=XOR[k+1]，当该式成立时，[i+1,k]的范围内的任意j都是符合要求的，对应的三元组个数为k-i


//双循环
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();
        vector<int> XOR(size+1);
        for(int i=0;i<size;i++)
            XOR[i+1]=XOR[i]^arr[i];
        int count = 0;
        for(int i=0;i<size;i++)
            for(int k=i+1;k<size;k++)
            {
                if(XOR[i]==XOR[k+1])
                    count += k-i;
            }
        return count;
    }
};

//一次for循环，对于下标k，若下标i=i1,i2,...,im（均小于k）时，都有XOR[i]=XOR[k+1]，
//根据上面的分析，这些二元组对答案的贡献为(k-i1)+(k-i2)+...+(k-im)=m*k - (i1+i2+...+im)
//在遍历下标k时，需要知道下标小于k的XOR中满足XOR[i]=XOR[k+1]的下标i的出现次数以及下标i之和
class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] ^ arr[i];
        }
        map<int, int> cnt, total;
        
        int ans = 0;
        //记录s[k]出现的次数和下标之和，由于i一定小于k，所以可以一次for循环，在遍历k时查找cnt中是否有s[k+1]即可
        for (int k = 0; k < n; ++k)
        {
            //if语句要写在下面cnt和total计算之前，因为当k=0时，不会有满足题意的i，所以这时一定不能计数
            if (cnt.count(s[k + 1]))
            {
                ans += cnt[s[k + 1]] * k - total[s[k + 1]];
            }
            cnt[s[k]]++;
            total[s[k]] += k;
        }          
        return ans;
    }
};

