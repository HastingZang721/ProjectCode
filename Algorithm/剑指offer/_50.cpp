#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>


#include <queue>
#include <set>
#include <math.h>

#include <string>
#include <iomanip>


using namespace std;

/*
 * 第一个只出现一次的字符
 *
 */

//解法1 ：暴力查询 从头开始扫描 every char 循环判断后面是否有字符与之相同

class SOlution1 {
public:
    int FirstCharNotRepeat(string str) {
        //条件判断
        if (str.length() == 0)
            return -1;

        bool Flag = false;
        unsigned int i, j;
        unsigned int len = str.length();
        for (int i = 0; i < len; i++)//对每一个字符遍历
        {
            Flag = true;
            if (str[i] == '\0') {
                continue;

            }
            cout << "str[" << setw(2) << i << "]=" << str[i] << endl;

            for (int j = i + 1; j < len; j++) {
//                 cout << "str[" << i << "]  " << str[i] << endl;
//                 cout << "str[" << j << "]  " << str[j] << endl;
                if (str[j] == '\0') {
                    continue;

                } else if (str[j] == str[i])//遍历发现有字符J和字符I的一样
                {
                    cout << str[i] << str[j] << endl;
                    str[j] = '\0';//停止向后遍历
                    Flag = false;


                }
            }
            if (Flag == true) {
                return i;

            }
        }
        return -1;

    }


};

//解法2 计数法；对只出现一次的字符会存储出现的位置，
//而出现多次的字符就标记为-1，最后遍历寻找出非-1 的最小位置即可
class Solution2 {
public:
    int FirstCharNotReapet(string str) {
        int x[26] = {0}, y[26] = {0};
        for (unsigned int i = 0; i < str.length(); i++) {
            //小写字母
            if ('a' <= str[i] && str[i] <= 'z') {
                if (x[str[i] - 'a'] == 0)//还未出现在字符串中
                {x[str[i] - 'a'] = i + 1;}//保存首次出现的位置

                else {
                    x[str[i] - 'a'] = -1;//出现多次 字符出现的设置为-1；


                }
                cout << str[i] << "," << x[str[i] - 'a'] << endl;

            }
            else if ('A' <= str[i] && str[i] <= 'Z') {
                if (y[str[i] - 'A'] == 0)
                    y[str[i] - 'A'] = i + 1;
                else {
                    y[str[i] - 'A'] = -1;

                }
                cout << str[i] << "," << y[str[i - 'A']] << endl;

            }
        }
        int res = INT8_MAX;
        for (unsigned int i = 0; i < 26;++i) {
            //小写字母存在且不为-1
            if (x[i] != 0 && x[i] != -1) {
                res = std::min(res, x[i]);


            }
            if (y[i] != 0 && y[i] != -1) {
                res = std::min(res, y[i]);
            }
            //return res > str.length() ? -1 : res - 1;



        }
        return res > str.length() ? -1 : res - 1;

    }


};


class SOlution3{
public:
    char FirstNotRepeatingChar(const char* pString)
    {
        if(pString == nullptr)
            return '\0';

        const int tableSize = 256;
        unsigned int hashTable[tableSize];
        for(unsigned int i = 0; i < tableSize; ++i)
            hashTable[i] = 0;

        const char* pHashKey = pString;
        while(*(pHashKey) != '\0')
            hashTable[*(pHashKey++)] ++;

        pHashKey = pString;
        while(*pHashKey != '\0')
        {
            if(hashTable[*pHashKey] == 1)
                return *pHashKey;

            pHashKey++;
        }

        return '\0';
    }

};


int main() {
    string str="dcawsdef";
//     SOlution1 s1;
//     cout<<s1.FirstCharNotRepeat(str);

    Solution2 solu2;
    cout<<solu2.FirstCharNotReapet(str);


    return 0;

}