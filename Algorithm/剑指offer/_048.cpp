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




using namespace std;

/*最长不重复字符的子字符串
 *
 *
 * 动态规划，用f(i)表示以i个字符结尾不包含重复子字符串的最长长度，从左向右扫描

1、若第i个字符在之前没出现过，则 f(i) = f(i-1) + 1;

2、若第i个字符在之前出现过，

计算第i个字符距离上次出现之间的距离为d

(a)若d <= f(i-1)，则说明第i个字符上次出现在f(i-1)对应的不重复字符串之内，那么这时候更新 f(i) = d

(b)若d > f(i-1)，则无影响,f(i) = f(i-1) + 1


 */


int LongestSubStringWIthoutDuplication(const std::string&str)
{
    int curLength=0;
    int maxLength=0;
    int *position=new int[26];
    for(int i=0;i<26;++i)
    {
        position[i]=-1;//用来记录每个字符上一次出现的
    }
    for(int i=0;i<str.length();++i)
    {
        int prevIndex=position[str[i]-'a'];//记录之前出现时的位置
        if(prevIndex<0||i-prevIndex>curLength)
            ++curLength;//符合条件1，和2.(b) 字符还没有出现或者是两相隔的距离大于前一个curlength
        else{
            if(curLength>maxLength)
                maxLength=curLength;

            curLength=i-prevIndex;

        }
        position[str[i]-'a']=i;

    }
    if(curLength>maxLength)
        maxLength=curLength;

    delete[] position;
    return maxLength;
}

int main(){
    string str1="asdewsdafcfwsxxfgdvbthjd";
    cout<<LongestSubStringWIthoutDuplication(str1);
    return 0;

}