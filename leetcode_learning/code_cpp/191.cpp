//解法一、遍历int型数32位每一位，看是否为1
class Solution{
public:
    int hammingWeight(int x){
        int cnt = 0;
        for(int i=0;i<32;i++)
            //判断第i位是否为1
            if(x&(1<<i))
            cnt++
        return cnt;
    }
};


//解法二、官方解法
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0)
        {
            n = n&(n-1);//消除n最后一位1
            count++;
        }
        return count;
    }
};


//解法三、将32位数分为8组，每组4位，每组的数从0000-1111，即0到15，对每组和15进行与运算，结果可以使用查表法
class Solution{
public:
    int hammingWeight(int x){
        int count = 0;
        for(int i=0;i<8;i++)
        {
            count += arr_cnt[(x>>(i*4)) & 0xf]//count += arr_cnt[(x>>(i*4)) & 15]
        }
    }
private:
    int arr_cnt[16] = {
    0,1,1,2,
    1,2,2,3,
    1,2,2,3,
    2,3,3,4
}
};
