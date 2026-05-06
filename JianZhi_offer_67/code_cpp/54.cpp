class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        s += ch;
        str_count[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            if(str_count[s[i]]==1)
                return s[i];
        }
        return '#';
    }
private:
    string s;
    map<char,int> str_count;
};

