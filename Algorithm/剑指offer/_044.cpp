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

/*
 *求数字序列中的某一位数字
 *
 * 0-9 共10位数
 * 10-99 共90个数字，180位
 * 100-999 共900个三位数 2700位
 *
 */

int countOfIntegerd(int m)//返回M位数字的总数：例如两位数的数字是10-99共90个
{
    if(m==1)
        return 10;
    int count=(int)std::pow(10,m-1);
    return 9*count;

}

int beginNumber(int digits)//知道M位数的第一个数字,第一个两位数是10

{
    if(digits==1)
        return 0;
    return (int)std::pow(10,digits-1);


}
int  digitAtIndex(int index,int m)//知道位于某M位数之后，找出那个数
{
    int number=beginNumber(m)+index/m;
    int indexFromRight=m-index%m;
    for(int i=1;i<indexFromRight;++i)
    {
        number/=10;
    }
    return number%10;



}
int digitAtIndex(int index)

{
    if(index<0)
        return -1;
    int digits=1;
    while(1)
    {
        int number=countOfIntegerd(digits);
        if(index<number*digits)
            return digitAtIndex(index,digits);
        
        
        index-=digits*number;
        digits++;
        
            
    }

    return -1;
    

}