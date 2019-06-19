#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<iterator>
#include<algorithm>
#include<exception>
using namespace std;

//String 容器
/*
 *
 *【】/at 两种不同的访问方法
 *
 */

//vector 容器：可变数组
//单口容器
/*push_back();
 * pop_back();
 * insert()//在指定位置插入元素，但建议在尾部操作
 * vector动态增长的基本原理
 *
 *
 *
 */
void Prinyvector(vector<int>&v)
{
    for(vector<int >::iterator it =v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;

    }
    cout<<endl;

}
////初始化
//void test1(){
//    vector<int >v1;
//    int arr[]={10,20,30};
//    vector<int>v2(arr,arr+sizeof(arr)/sizeof(int));
//    vector<int >v3(v2.begin(),v2.end());
//    vector<int >v4(v3);
//
//    Prinyvector(v2);
//
//
//
//
//
//}

void test2(){
    //vector<int >v1;
    int arr[]={10,11,12,131,15};
    vector<int >v2(arr,arr+sizeof(arr)/sizeof(int));
    vector<int>v3(v2);
    //cout<<v3.size()<<endl;
    v3.erase(v3.begin());
    v3.erase(v3.begin()+1,v3.end());
    Prinyvector(v3);
    v3.clear();

    cout<<v3.size()<<endl;




}
//
int main(){

    test2();
    return 0;

}





