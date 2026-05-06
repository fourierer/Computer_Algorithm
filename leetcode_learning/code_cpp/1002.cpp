#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int length = A.size();
        if(length==0)
            return v;
        map<char, int> char_global_min_count;
        map<char, int> char_local_min_count;
        //初始化字母全局最少次数字典，均赋值为INT_MAX
        char_global_min_count = global_min();

        //遍历字符数组A，计算每个字符的局部最少次数，同时更新全局最少次数
        for(int i=0;i<length;i++)
        {
            //初始化字母局部最少次数字典均为0
            char_local_min_count = local_min();

            int len = A[i].length();
            //计算当前字符每个字母出现的最少次数
            for(int j=0;j<len;j++)
            {
                char_local_min_count[A[i][j]]++;
            }

            //更新字母全局最少次数字典
            for(int s = 0; s<26; s++)
            {
                char_global_min_count['a'+s] = min(char_global_min_count['a'+s], char_local_min_count['a'+s]);
            }
        }
        /*
        //测试字母全局最少次数字典
        for(map<char, int>::iterator it=char_global_min_count.begin();it!=char_global_min_count.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        */

        //根据字母全局最少次数字典来返回字符数组
        for(int s = 0; s<26; s++)
        {
            if(char_global_min_count[char('a' + s)]>0)
            {
                string s1(1, char('a' + s));
                for(int k=0;k<char_global_min_count[char('a' + s)];k++)
                    v.push_back(s1);
            }         
        }
        return v;
    }

private:
    vector<string> v;
    map<char, int> local_min()
    {
        map<char, int> char_local_min_count;
        for(int s = 0; s<26; s++)
        {
            //cout<<char('a' + s)<<endl; //依次输出26个字母
            char temp = 'a' + s;
            //初始化字母局部最少次数字典，均赋值为0
            char_local_min_count[temp] = 0;
        }
        return char_local_min_count;
    }

    map<char, int> global_min()
    {
        map<char, int> char_global_min_count;
        for(int s = 0; s<26; s++)
        {
            //cout<<char('a' + s)<<endl; //依次输出26个字母
            char temp = 'a' + s;
            //初始化字母全局最少次数字典，均赋值为最大数
            char_global_min_count[temp] = INT_MAX;
        }
        return char_global_min_count;
    }
};


int main()
{
    map<char, int> char_global_min_count;
    map<char, int> char_local_min_count;
    /*
    for(int i = 0; i<26; i++)
    {
        //cout<<char('a' + i)<<endl; //依次输出26个字母
        char temp = 'a' + i;
        //初始化字母全局最少次数以及字母局部最少次数，均赋值为最大数
        char_global_min_count[temp] = INT_MAX;
        char_local_min_count[temp] = INI_MAX;
    }
    */
    string s1 = "cool";
    string s2 = "lock";
    string s3 = "cook";
    vector<string> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    Solution s;
    vector<string> v_ = s.commonChars(v);
    cout<<v_.size();
    for(int i=0;i<v_.size();i++)
        cout<<v_[i]<<endl;

    /*
    for(map<char, int>::iterator it=char_global_min_count.begin();it!=char_global_min_count.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    */
    return 0;
}