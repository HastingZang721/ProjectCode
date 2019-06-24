#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

#include<cmath>

using namespace std;
//数值的整数次方(利用位运算)
//用右移代替除法；
//用 与 运算代替% 来判断是否为奇数
class Solution{
public:
    double PowerwithUnsignedExponent(double base, unsigned int exponent)
    {
        if(exponent==0)
            return 1;
        if(exponent==1)
            return base;
        double result=PowerwithUnsignedExponent(base,exponent>>1);
        result*=result;//当exponent 为偶数；
        if(exponent& 1==1)//exponent 为奇数
        {
            result*=base;
        }
        return result;

    }
    bool IsEqual(double num1,double num2)
    {
        int a=1e-8;
        //if (fabs((num1-num2)<a))
        if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
            return  true;
        else
            return false;

    }
    double power(double base ,int exponent)
    {
        InvalidInput=false;
        if(IsEqual(base,0.0)&& exponent<0)//指数为负数且底为0

        {
            InvalidInput=true;
            return 0.0;

        }
        unsigned int absExponent=(unsigned int )(exponent);
        if(exponent<0)
            absExponent=(unsigned int)(-exponent);
        double result=PowerwithUnsignedExponent(base,absExponent);
        if(exponent<0)
            result=1.0/result;

        return result;


    }

public:
    bool InvalidInput=false;


};

void test(const char* testname,double base,int exponent,double expectedResult,bool expectedFlag)
{
    Solution solu;

    double result= solu.power(base,exponent);
    if(solu.IsEqual(result,expectedResult)&&expectedFlag==solu.InvalidInput)
        cout<<testname<<"  passed"<<endl;
    else
        cout<<testname<<"  failed"<<endl;


}



int main(){
    test("test1",2,3,8,false);
    test("test2",2,-3,0.125,false);
    return 0;
}