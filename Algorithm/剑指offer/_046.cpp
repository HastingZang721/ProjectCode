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


#include <sstream>

#define  Random(  x)rand()%x;//生成0-x之间的随机整数
using namespace std;

/*
 把数字翻译成字符串

 思路：问题可以被拆分为多个子问题求解，且子问题有重叠部分
 状态转移方程有：
       f(i-1)+f(i-2), 10<=c(i-1,i)<=25
f(i)=
      f(i-1), otherwise
 */

/*
 *
 * 数字转化成字符串
 *   int main(){
    double a = 123.32;
    string res;
    stringstream ss;          定义流ss
    ss << a;                       将数字a转化成流ss
    ss >> res;                    将流ss转化成字符串
    return 0;
  }



 */

class  SOlution{
public:
    int To_string(int num)
    {
        string res;
        stringstream ss;
        ss<<num;
        ss>>res;
        return  TranslationCount(res);


    }

    int TranslationCount(const string& number)
    {
        int length=number.length();
        int* counts=new int[length];
        int count=0;//记录不同翻译的数目

        for(int i=length-1;i>=0;i--)//从后往前翻译并计算
        {
            count=0;
            if(i<length-1)
            {
                count=counts[i+1];//记录前一位的count值

            }
            else
                count=1;

            if(i<length-1)
            {
                int digit1=number[i]-'0';
                int digit2=number[i+1]-'0';
                int converted=digit1*10+digit2;
                //判断第i位和第i+1位的数字拼接起来的值是否在10-25之间
                if(converted<=25&&converted>=10)
                {
                    if(i<length-2)//还没遍历结束
                        count+=counts[i+2];//count值添加covert的翻译方法值
                    else
                        count+=1;

                }
            }
            counts[i]=count;



        }
        count=counts[0];
        delete[] counts;

        return count;




    }

};

int main(){
    int a=Random(100000);
    cout<<"随机生成整数 a: "<<a<<endl;
    SOlution solu1;
    cout<< "翻译的数目有： "<<solu1.To_string(a)<<endl;



    return 0;

}


