#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>


using namespace std;
//表示数值的字符串

bool scanUsignedInteger(const char **str);//检查是否有B类型的，即可以是0-9的数位串，但不能有正负号
bool scanInteger(const char **str);//检查是否有A/C类型的,即可以是以正负号开头的的0-9的数位串
bool isNumberic(const char *str) {
    if (str == nullptr)
        return false;
    bool numric = scanInteger(&str);

    //若出现小数.
    if (*str == '.') {
        ++str;
        numric = scanUsignedInteger(&str) || numric;//小数部分可以没有整数，

    }
    //如果出现e 则到达指数部分
    if (*str == 'e' || *str == 'E') {
        ++str;
        numric = numric && scanInteger(&str);//e的前后必须是有数字

    }
    return numric && *str == '\0';


}

bool scanUsignedInteger(const char **str) {
    const char *before = *str;
    while (**str != '\0' && **str >= '0' && **str <= '9') {
        ++(*str);
        return *str > before;
    }

}

bool scanInteger(const char **str) {
    if (**str == '+' || **str == '-') {
        ++(*str);
    }
    return scanUsignedInteger(str);

}

void test(const char *testname, const char *str, bool expected) {
    if (testname != nullptr)
        cout << testname << " begins";
    if(isNumberic(str) == expected)

        cout << "  passed" << endl;
    else
        cout << "  failed" << endl;
}

int main() {
    test("test1", "5e2", true);
    test("test2", "12e", false);
    return 0;

}