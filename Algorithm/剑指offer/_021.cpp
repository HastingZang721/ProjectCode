#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>


using namespace std;
//调整数组顺序将奇数位置于偶数前面
//思路：1 ，前后两个指针，每次扫描后交换偶数与奇数的位置
class SOlution{
public:
    void Recorder(int * pData, unsigned int length,bool(* func)(int ));
    static bool isEven(int n);
    void RecorderOddEven(int *pData, unsigned int length){Recorder(pData,length,isEven);}



};

void SOlution::Recorder(int *pData, unsigned int length, bool (* func)(int) )
{
    if(pData== nullptr||pData==0)
        return ;
    int *pBegin=pData;
    int *pEnd=pData+length+1;

    while(pBegin<pEnd)
    {
       // while (pBegin<pEnd&&(*pBegin&1)!=0)//向后移动pBegin ,直到它指向偶数
       while(pBegin<pEnd&&!func(*pBegin))
           pBegin++;

       while(pBegin<pEnd&& func(*pEnd))//向前移动pEnd,直到它指向奇数
           pEnd--;
       if(pBegin<pEnd)//交换奇偶的位置
       {
           int temp=*pBegin;
           *pBegin=*pEnd;
           *pEnd=temp;

       }

    }


}


bool SOlution::isEven(int n) {
    return (n&1)==0;
}



int main(){
    SOlution solu;
    int p[]={1,2,3,4,5,7};
    solu.RecorderOddEven(p,6);
    for(int i=0;i<6;i++)
        cout<<p[i]<<" ";
    return 0;
}

