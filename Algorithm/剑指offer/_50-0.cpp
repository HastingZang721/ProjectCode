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


char FirstNotReaptingChar(char *string1)
{
    if(string1==NULL)
        return '\0';
    int hashTable[256]={0};
    char*p=string1;
    while(*p)
    {
        hashTable[*p]++;
        p++;

    }

    p=string1;//p用重新指向string1的起始地址，进行第二次遍历

    while(*p)
    {
        if(hashTable[*p]==1)
            return *p;
        p++;


    }
    return '\0';





}

void test1(){
    char first[]="sheqefysjcoakds";
    cout<<FirstNotReaptingChar(first);



    //cout<<first<<endl;

}

int main(){
    test1();
    return 0;

}