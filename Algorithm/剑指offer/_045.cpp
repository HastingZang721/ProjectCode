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


#include <sstream>

using namespace std;

/*
 *如何给这个数组排序，使其看做一个数字的时候最小
 *
 * 按照拼接的结果来排序
 *
 *
 * 思路：先将整数数组转为字符串数组，然后字符串数组进行排序，最后依次输出字符串数组即可。
 * 这里注意的是字符串的比较函数需要重新定义，不是比较a和b，而是比较ab与 ba。
 * 如果ab < ba，则a < b；如果ab > ba，则a > b
 */




template<typename T> string ToString(const T& t){
    ostringstream oss;  //创建一个格式化输出流
    oss<<t;             //把值传递如流中
    return oss.str();
}

class SOlution {
public:
    static bool Compare(const string &left, const string &right) {
        string leftright = left + right;
        string rightleft = right + left;
        if (leftright > rightleft) {
            cout << rightleft << "<" << leftright << "--" << rightleft << endl;

        } else {
            cout << leftright << "<" << rightleft << "--" << leftright << endl;

        }
        return leftright < rightleft;
    }

    string PrintMinNUmber(vector<int> number) {
        string str;
        vector<string> strnum;
        //将整数数组转化为字符串数组
        for (unsigned int i = 0; i < number.size(); i++) {
            str = ToString(number);
            strnum.push_back(str);
            cout << str <<" ";

        }
        //对拼接后的大小进行排序
        sort(strnum.begin(), strnum.end(), Compare);
        string res;

        //显示拼接结果
        for (unsigned int i = 0; i < strnum.size(); i++) {
            cout << strnum[i] << endl;
            res += strnum[i];

        }
        cout << endl;
        return res;


    }
};

int main(){
    int arr[]={3,32,321};
    vector<int>number(arr,arr+3);
    SOlution solu1;
    cout<<solu1.PrintMinNUmber(number);


    return 0;

}


