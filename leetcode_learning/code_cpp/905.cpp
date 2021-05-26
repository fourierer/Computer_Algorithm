//解法一、暴力冒泡，两个for循环，遇到相邻的奇偶就互换位置,O(n^2)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for(int i=0;i<A.size();i++)
            for(int j=i;j<A.size();j++)
                if(A[i]%2==1&&A[j]%2==0)
                    swap(A[i], A[j]);
        return A;
    }
};


//解法二、重新改写排序规则，新的排序规则：奇数“大于”偶数,O(nlogn)
bool compare(int& x, int& y)
{
    if(x%2==0&&y%2==1)
        return true;
    return false;
}
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A)
    {
        sort(A.begin(), A.end(), compare);
        return A;
    }
};

//解法三、双指针遍历
class Solution{
public:
    vector<int> sortArrayByParity(vector<int>& A)
    {
        //遍历一遍数组，记录偶数个数
        int flag = 0;
        for(int i=0;i<A.size();i++)
            if(A[i]%2==0)
                flag++;
        int i = 0;
        int j = flag;
        //while循环一定要有j<A.size()，否则里面循环的j会出界，以及当数组全为偶数时，也能返回正确答案
        while(i<flag&&j<A.size())
        {
            if(A[i]%2==0&&A[j]%2==1)
            {
                i++;
                j++;
            }
            else if(A[i]%2==0&&A[j]%2==0)
                i++;
            else if(A[i]%2==1&&A[j]%2==1)
                j++;
            else
            {
                swap(A[i],A[j]);
                i++;
                j++;
            }
        }
        return A;
    }
};

