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
 * 丑数：n%m==0,则说明M是N的因子


 */


//解法1：----------------逐个判断每个整数是不是丑数
class SOlution1{
public:
    bool Is_ugly(int number)
    {
        while(number%2==0)
            number/=2;
        while (number%3==0)
            number/=3;
        while (number%5==0)
            number/=5;

        return (number==1)?true: false;
    }
    int GetUglyNUmber(int index)
    {
        if(index<=0)
            return 0;
        int number=0;
        int uglyFoundNum=0;
        while(uglyFoundNum<index)//一直找到1500（index）个丑数
        {
            ++number;
            if(Is_ugly(number))//判断是否为丑数
            {
                ++uglyFoundNum;
            }
        }
        return number;//返回符合第index的丑数

    }



};


class SOlution2{
public:
    int GetUglyNumber_SOlution2(int index)
    {
        if(index<=0)
            return 0;

        int Ugly[index];

        Ugly[0]=1;//定义第一个丑数是1
        int N2=0;
        int N3=0;
        int N5=0;
        int N=1;
        while(N<index)
        {
            int val=min(Ugly[N2]*2,Ugly[N3]*3,Ugly[N5]*5);
            if(val==Ugly[N2]*2)
            {
                ++N2;

            }
            if(val==Ugly[N3]*3)
            {
                ++N3;

            }

            if(val==Ugly[N5]*5)
            {
                ++N5;

            }
            Ugly[N++]=val;

        }
        int result=Ugly[N-1];
        return result;

    }
    int min(int a,int b,int c)
    {
        int temp=(a<b)?a:b;
        return (temp<c)?temp:c;
    }

};
void test1()
{
    SOlution1 solu1;
    cout<<solu1.GetUglyNUmber(150);
}



int main(){
    test1();
    return 0;

}