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
 * 统计数组中出现的逆序对
 *
 * 思路一：暴力解法 做两次循环，挨个比较前一个数组是否大于后一个（此处省略）
 * 思路2：是冒泡排序 ，每交换一次就说明有一个逆序对（时间复杂度还是同上O（N2））
 * 思路3：归并
 */
//思路2：
class Solution2{
public:
    int InversePairs(int a[],int len)
    {
        if(a== nullptr||len<=0)
            return 0;
        else
            return BubbleSwapcount(a,len);


    }

    int BubbleSwapcount(int a[],int len)
    {

        int count=0;
        for(int i=0;i<len-1;i++)
        {
            for(int j=0;j<len-1-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    std::swap(a[j],a[j+1]);
                    count++;
                }
            }
        }
        return count;

    }
};

//解法三 归并：1 先将数组分割成子数组，统计子数组内部的逆序对数目，然后统计两不相邻子数组之间的逆序对数目，
//同时在统计逆序对的过程，需要对数组进行排序
class SOlution3{
public:
    int InversePairs(int*data,int length)
    {
        if(data== nullptr||length<0)
        {
            return 0;

        }
        int* copy=new int [length];
        for(int i=0;i<length;++i)
        {
            copy[i]=data[i];
        }
        int count=InversePairsCore(data,copy,0,length-1);

        delete[] copy;
        return count;

    }

    int InversePairsCore(int *data,int *copy,int start,int end)

    {
//未明
    }
};






void test1(){
    int a[4]={7,5,6,4};
//    Solution2 solu2;
//    cout<<solu2.InversePairs(a,4);
}


int main(){
    test1();
    return 0;
}
