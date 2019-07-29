lude<iostream>
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
 * 输入两个字符串，从第一个字符串中删除在第二个字符串中出现的所有字符
 *
 */


void DelteFromString2(char  *first,char *second)

{
    if(second==NULL)
        return;
    int hashtable[256];
    char*p=second;
    while(*p)//将 second的字符存储记录在hashtable 中
    {
        hashtable[*p]=1;
        p++;

    }

    char  *slow=first;//slow 用于记录最后删除的string first
    char  *fast=first;//fast 用于遍历
    while(*fast)
    {
        if(hashtable[*fast]==0)
        {
            *slow=*fast;
            slow++;

        }
        fast++;

    }
    *slow='\0';



}


void test1(){
    char first[]="sheqefysjcoakds";
    char second[]="aeiou";
    DelteFromString2(first,second);
    cout<<first<<endl;

}

int main(){
    test1();
    return 0;

}