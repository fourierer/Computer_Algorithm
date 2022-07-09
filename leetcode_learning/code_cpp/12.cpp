#include<iostream>
#include<string>
#include<map>

using namespace std;

//模拟编码
//写出所有编码情况，按照从大到小依次对num进行编码
class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        while(num>=1000)
        {
            result += value_symbol[1000];
            num -= 1000;
        }

        while(num>=900)
        {
            result += value_symbol[900];
            num -= 900;
        }

        while(num>=500)
        {
            result += value_symbol[500];
            num -= 500;
        }

        while(num>=400)
        {
            result += value_symbol[400];
            num -= 400;
        }
        
        while(num>=100)
        {
            result += value_symbol[100];
            num -= 100;
        }

        while(num>=90)
        {
            result += value_symbol[90];
            num -= 90;
        }

        while(num>=50)
        {
            result += value_symbol[50];
            num -= 50;
        }

        while(num>=40)
        {
            result += value_symbol[40];
            num -= 40;
        }

        while(num>=10)
        {
            result += value_symbol[10];
            num -= 10;
        }
        
        while(num>=9)
        {
            result += value_symbol[9];
            num -= 9;
        }

        while(num>=5)
        {
            result += value_symbol[5];
            num -= 5;
        }

        while(num>=4)
        {
            result += value_symbol[4];
            num -= 4;
        }
        
        while(num>=1)
        {
            result += value_symbol[1];
            num -= 1;
        }
        return result;
    }
private:
    map<int, string> value_symbol = {
        {1, "I"},
        {5, "V"},
        {10, "X"},
        {50, "L"},
        {100, "C"},
        {500, "D"},
        {1000, "M"},
        //增加额外编码
        {4, "IV"},
        {9, "IX"},
        {40, "XL"},
        {90, "XC"},
        {400, "CD"},
        {900, "CM"}
    };
};

