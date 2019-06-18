#include<iostream>
//#include<queue>
#include<cstdio>
#include<math.h>

using namespace std;
//异常机制
//C+异常跨函数，且必须处理
//
//int divide(int x,int y)
//{
//    if(y==0)
//    {
//        throw y;
//
//    }
//    return x/y;
//}
//
//void test0(){
//    try{
//        divide(10,0);
//
//    }
//    catch (int e)//根据类型进行匹配
//    {cout<<"Error"<<endl;}
//}
//int main(){
//    test0();
//
//}
/////////////////////////////////////////////棧解旋
//class Person{
//public:
//    Person(){cout<<"对象构建"<<endl;};
//    ~Person(){cout<<"对象析构"<<endl;};
//
//};
//
//
//int divide(int x,int y){
//    Person P1,P2;//函数一但出现出现异常，调用析构函数
//    if(y==0)
//    {throw y;}
//    return x/y;
//
//
//}
//void test1(){
//    try{
//        divide(10,0);
//
//    }
//    catch(int){
//        cout<<"Error"<<endl;
//
//
//
//    }
//
//}
//int main(){
//
//    test1();
//    return 0;
//
//}
//

////thorw 的异常类型有数字，字符串 和类对象


class MyException{
public:
    MyException(char* str);
    perror=new char[strlen(str)+1];
    strcpy(perror,str);
    ~MyException(){
        if(perror!=NULL)
            delete[] perror;

    }
    MyException (const MyException& ex)//复制构造函数
    {
        this->perror=new char[strlen(ex.perror)+1];
        strcpy(this->perror,ex.perror);


    }
    //重载=
    MyException& operaotr(const MyException& ex){
        if(this->perror!=NULL)
            delete[] perror;
        this->perror=NULL;
        this->perror=new char[strlen(ex.perror)+1];
        strcpy(this->perror,ex.perror);


    }





    void what(){
    cout<<"未知异常"<<endl;

}

public:
    char* perror;
    char str;
};


void func3(){
    throw MyException("我刚写的异常");
}


void test1(){

    try{
        func3();

    }
    catch(MyException e ){
        e.what();



    }
}
int main(){

    test1();
    return 0;

}













































