#include<iostream>
#include<cstdio>

#include<string>
#include<typeinfo>
//C+中类型转换
using namespace std;
//static_<cast>
//dynamic_<cast>在基类和派生类的转换
//const_<cast>
//reinterpret_<cast>

//static _<cast>


class Buliding{};
class Animals{};
class Dog:public Animals{};



//
//void test1(){
//    int a=10;
//    char c= static_cast<char>(a);
////    cout<<c;
////    cout<< typeid(c).name();
//
////指针
////    int*p=NULL;
////    char*sp= static_cast<char*>(p);//No
//
//    //对象类型指针
////    Buliding* buliding=NULL;
////    Animals* animals= static_cast<Animals*>(buliding);//No
//    //转换具有继承关系的对象指针
//
//    //父类指针转换城子类指针
//    Animals* ani=NULL;
//    Dog* dd= static_cast<Dog*>(ani);
//    //子类指针转化为父类指针
//    Dog *dd1=NULL;
//    Animals ann1= static_cast<Animals*>(dd1);
//
//
//
//
//}
//dynamic_<cast>转换具有继承类型的指针或者引用
void test2(){
    //继承关系
    Animals* ani=NULL;
    Dog* dd= dynamic_cast<Dog*>(ani);//error
    //父类（小）对象无法转换城子类（大），不安全 ，反之则可以

    Dog* dd1=NULL;
    Animals* ani1= dynamic_cast<Animals*>(dd1);

}


int main(){
    //test1();
    test2();

    return 0;

}