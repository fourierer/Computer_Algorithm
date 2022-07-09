//解法一、判断反转后的数和原数是否相同
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return 0;
        long flip = 0;
        long temp = 0;
        int store_x = x;
        while(x!=0)
        {
            temp = x%10;
            flip = 10*flip + temp;
            x = x/10;
        }
        return flip==store_x;
    }
};

//解法二、使用字符串，判断首尾是否相同
class Solution{
public:
    bool isPalindrome(int x) {
        if(x<0)
            return 0;
        string s = to_string(x);
        int i = 0;
        int j = s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

