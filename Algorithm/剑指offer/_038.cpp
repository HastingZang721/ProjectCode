#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>



#include <queue>

using namespace std;

/*
 *字符串的排列
 *
 */

void Permutation(char* pstr,char* pBegin);

void Permutation(char* pstr)
{
    if(pstr== nullptr)
        return ;

    Permutation(pstr,pstr);

}

void Permutation(char* pstr,char *pBegin)//pBegin 指向当前执行排列的第一个字符
{
    if(*pBegin=='\0')//直到pbegin指向末尾
    {
        cout<<pstr<<endl;
    }

    else{
        for(char* ch=pBegin;*ch!='\0';++ch)
        {
            //将第一个字符与它后面的字符逐个交换   swap(*pBegin,*ch)
            char temp=*ch;
            *ch=*pBegin;
            *pBegin=temp;

            Permutation(pstr,pBegin+1);//每次递归 pBegin向后扫描每一个字符

            temp=*ch;//swap(*pBegin,*ch)
            *ch=*pBegin;
            *pBegin=temp;


        }

    }
}
