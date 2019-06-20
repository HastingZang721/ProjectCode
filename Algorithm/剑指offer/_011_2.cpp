#include<iostream>
#include<stdio.h>
#include<cstdio>
#include <cstring>
#include<vector>
#include<iterator>
#include<algorithm>
#include<exception>
#include<stack>
#include<cmath>

using namespace std;

//求数值的整数次方
/*应该分为指数是0，负数，正数 三种情况*/


//
//
//class Solution{
//public:
//
//    double Pow(double base,int exponent)
//    {
//        if(exponent==0)
//        {
//            return 1.0;
//        }
//        else if(exponent<0)
//        {
//            if(base==0)
//            {
//                cout<<"Error,指数为负数，底数不可为0"<<endl;
//                return 0;
//
//            }
//            double a=1,res=1;
//            for(int i=0;i< abs(exponent);i++)
//            {
//                a*=base;
//                res=1/a;
//
//            }
//            return res;
//
//
//        }
//        else
//        {
//            double res=1;
//            for(int i=0;i<exponent;i++)
//            {
//                res*=base;
//
//            }
//            return res;
//
//
//        }
//
//    }
// };
//int main(){
//    Solution solu;
//    double an=solu.Pow(2,-3);
//    cout<<"an: "<<an<<endl;
//    double a1=solu.Pow(2,3);
//    cout<<"a1: "<<a1<<endl;
//    return 0;
//
//
//}
////解法2：位运算类；
double PowerNormal(double base, int exponent)
{
    if(exponent == 0)
    {
        return 1;
    }
    else if(exponent == 1)
    {
        return base;
    }

    int res = 1, temp = base;
    while(exponent != 0)
    {
        if((exponent & 1) == 1) //  当前指数为不为0
        {
            res *= temp;        //  就计算一个乘积
        }
        //  移位后, curr需要翻倍, 这样到下个
        temp *= temp;           // 翻倍
        exponent >>= 1;         // 右移一位
    }
    return res;
}