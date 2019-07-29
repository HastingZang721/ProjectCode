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
 * 删除字符串中重复出现的字符
 *
 * 思路：和别的运用哈希表类似，但是这次可以使用bool数组来实现简单的哈希表
 *
 */


void DeleteRepeatChar(char *string1)

{
    if(string1==NULL)
        return;
    bool hashtable[256]={false};//先全部设置为false
    char *pfast=string1;
    char *pslow=string1;
    while(*pfast)
    {


        if(!hashtable[*pfast])//pfast指向的字符未被访问
        {

            hashtable[*pfast]=1;
            *pslow=*pfast;
            pslow++;

        }
        pfast++;


    }
    *pslow='\0';


}

void test1(){
    char first[]="sswdefscrvdddcs";
    DeleteRepeatChar(first);
    cout<<first<<endl;

}

int main(){
    test1();
    return 0;

}