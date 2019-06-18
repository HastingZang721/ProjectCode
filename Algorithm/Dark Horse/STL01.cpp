#include<iostream>
#include<cstdio>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

//STL
//standard Template library
//数据结构与算法分离
//容器：序列 关联
//迭代器： 相当于指针，实际上迭代器是一个类，封装成一个指针
//算法：通过有限的步骤解决问题

//int mycount(int* start,int* end,int val){//算法，负责统计元素的个数
//    int num=0;
//    while(start!=end)
//    {
//        if(*start==val)
//        {num++;}
//        start++;
//
//
//    }
//    return num;
//
//
//}
//
//int main(){
//    //数组  容器
//    int arr[]={0,7,4,2,1,5,7,34,1};
//    int* pbegin=arr;//指向第一个元素的其位置
//    int* pend=&(arr[sizeof(arr)/sizeof(int)]);//指向迭代器最后一个元素的下一个位置
//    int number=mycount(pbegin,pend,1);
//    cout<<number<<endl;
//
//
//}
///////////////------------------------------------------------------------


//STL 基本语法

//void PrintVector(int v){
//
//    cout<<v;
//}
//
//void test1(){
//    vector<int >v;//定义一个容器，且指定这个容器存放的数据类型是int
//    v.push_back(10);
//    v.push_back(20);
//    v.push_back(40);
//
//    //vector<int>::iterator 迭代器类型
//
//    vector<int >::iterator pBegin=v.begin();
//    vector<int >::iterator pEnd=v.end();
//
//
//
//    //容器提供的迭代其for_each算法
//
//    for_each(pBegin,pEnd,PrintVector);
//
//
//}
//容器也可以存放自定义的数据类型

class Person{
public:
    Person(int age,int id):age(age),id(id){}

public:
    int age;
    int id ;
};


void PrintVector(Person v){

    cout<<v.id<<" "<<v.age<<endl;
}


int test2(){
    vector<Person>v;
    Person p1(10,20),p2(2,40);
    v.push_back(p1);
    v.push_back(p2);

//
//    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
//    {
//        cout<<(*it).age<<" "<<(*it).id<<endl;
//
//    }

    vector<Person >::iterator pBegin=v.begin();
    vector<Person >::iterator pEnd=v.end();
    for_each(pBegin,pEnd,PrintVector);


}//容器中存放Person类行的指针，并且打印for_each或者迭代器方式进行打印

int main(){
    //test1();
    test2();

    return 0;
}