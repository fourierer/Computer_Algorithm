class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        if(length==0)
            return;
        int i=0;
        int j = length - 1;
        while(i<j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

/*
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int left = 0, right = n - 1; left < right; ++left, --right) {
            swap(s[left], s[right]);
        }
    }
};
*/