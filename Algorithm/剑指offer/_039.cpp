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
 *
 *数组中出现次数超过一半的数字
 *

 */
template <class T>
void Myswap(T &x,T & y)
{
    T temp=x;
    x=y;
    y=temp;

}



int Partition(int a[],int start,int end)
{
    int pivot=a[start];
    while(start<end)
    {
        while(start<end&& a[end]>=pivot)
            end--;
        Myswap(a[start],a[end]);
        while(start<end&&a[start]<=pivot)
            start++;
        Myswap(a[start],a[end]);

    }

    a[start]=pivot;

    return start;
}


bool g_bInputvalid=false;//考虑无效的输入
bool CheckinvalidArray(int *number,int length)

{
    g_bInputvalid=false;
    if(number== nullptr||length<0)
        g_bInputvalid=true;
    return g_bInputvalid;


}

bool CheckMoreThanHalf(int *numbers,int length,int number)
//检查是否有符合题意超过半数的数字出现

{
    int times=0;
    for(int i=0;i<length;++i)
    {
        if(numbers[i]==number)
            times++;

    }
    bool isMoreThanHalf=true;
    if(times*2<=length)
    {
        g_bInputvalid=true;
        isMoreThanHalf=false;

    }
    return isMoreThanHalf;

}

int MoreThanHalfOfNum_solution1(int* numbers,int length)
{
    if(CheckinvalidArray(numbers,length))
        return 0;
    int middle=length>>1;//右移1位，减半
    int start=0;
    int end=length-1;

    int index=Partition(numbers,start,end);
    while(index!=middle)
    {
        if(index>middle)//下标大衣一半，中位数应该位于左边
        {
            end=index-1;
            index=Partition(numbers,start,end);

        }
        else
        {
            start=index+1;
            index=Partition(numbers,start,end);

        }
    }
    int result=numbers[middle];
    if(!CheckMoreThanHalf(numbers,length,result))
        result=0;

    return result;





}


int MOreTahHalfSOlution2(int * numbers,int length)
{
    if(CheckMoreThanHalf(numbers,length))
        return 0;
    int result=numbers[0];
    int times=1;
    for(int i=1;i<length;++i)
    {
        if(times==0)
        {
            result=numbers[i];
            time=1;
            //要找的数字一定是最后一次吧次数设置为1所对应的数字
        }
        else if(numbers[i]==result)
            times++;
        else
            times--;

    }
    if(!CheckMoreThanHalf(numbers,length,result))
        result=0;
    return result;
    
}



























