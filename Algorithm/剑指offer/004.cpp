//替换空格
#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

////暴力替换
//
//class Solution {
//
//public :
//    void replaceSpace(char *str, int length) {
//        int i = length - 1,j;
//        int len = length;//len 表示新的数组长度
//
//
//        //从后往前遍历
//        for (i = length - 1; i >= 0; i--) {
//            if (str[i] == ' ') {
//                len += 2;
//                for(j=len-1;j>i+2;j--)
//                {
//                    str[j]=str[j-2];
//
//                }
//                str[j--]='0';
//                str[j--]='2';
//                str[j--]='\%';
//
//
//            }
//            //cout<<str<<endl;
//
//
//        }
//        str[len]='\0';
//    }
//};
//
//int main(){
//    char str[10+1]="a b c d";
//    Solution solu;
//    solu.replaceSpace(str,10);
//    cout<<str<<endl;
//
//}
//o(n)
//遍历一遍字符串， 统计字符出现的数目, 计算替换后的字符串长度
//
//再遍历一遍字符串，完成替换
class Solution{
public :
    void repalceSpace(char *str,int length)
    {
    int i,j;
    int count=0;
    int len=length;
    for(int i=0;i<length;i++)
    {
        if(str[i]==' ')
            count++;

    }
    len=length+count*2;
    for(i=length-1,j=len-1;i>=0&&j>=0;)
    {
        if(str[i]==' ')
        {
            str[j--]='0';
            str[j--]='2';
            str[j--]='\%';

            i--;

        }
        else
            str[j--]=str[i--];


    }
    str[len]='\0';



    }
};



//==============测试用例=================
void Test(char* testname,char* str,int length,char excepted[])
{
    if (testname !=nullptr)
        cout<<testname<<"  starts"<<endl;
    Solution solu;
    solu.repalceSpace(str,length);
    if(excepted== nullptr&&str== nullptr)
        cout<<"passed"<<endl;
    else if(strcmp(str,excepted)==0)//相等时返回0
        cout<<"passed"<<endl;
    else
        cout <<"failed"<<endl;



}
void Test1()
{
    const int length=100;
    char str[length]="hello hasting";
    Test("Test1",str,length,"hello%20hasting");
}


void Test2()
{
    const int length=100;
    char str[length]="hello";
    Test("Test2",str,length,"hello");
}

void Test3()
{
    const int length=100;
    char str[length]="h e l l o";
    Test("Test1",str,length,"h%20e%20l%20l%20o");
}


int main() {
    //Test1();
    //Test2();
    Test3();
    return 0;
}
