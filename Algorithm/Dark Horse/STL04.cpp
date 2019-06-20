#include<iostream>

#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

#include<cmath>
#include<set>
#include<map>
#include<utility>

//
using namespace std;
////关联容器
//
////set 集合 ；元素不可重复
//// /multiset 多重集合；元素可重复
////set 常用API
//
//void test1(){
//    set<int >a;
//    a.insert(1);
//    a.insert(4);
//    a.insert(2);
//    for(set<int>::iterator it=a.begin();it!=a.end();it++)
//    {
//        cout<<(*it)<<endl;
//
//    }
//}
//
//
//int main(){
//
//    test1();
//    return 0;
//
//}
//
//////////二元关联容器
/*
 * map 映射：类字典
 *
 * multimap 多重映射
 * pair<键类型，附加数据类型>
 *
 *
 */
//5门课程 每门都有相应的学分，从中选择3门，输出学分总和
int main(){
    map<string,int>courses;
    //将课程信息插入courses 映射中

    courses.insert(make_pair("csapp",3));
    courses.insert(make_pair("math",4));
    courses.insert(make_pair("chinese",2));
    courses.insert(make_pair("english",2));
    courses.insert(make_pair("os",5));

    int n=3;
    int sum=0;
    while(n>0){
        string name;
        cin>>name;
        map<string ,int>::iterator it=courses.find(name);//查找课程
        if(it==courses.end())
        {
            cout<<name<<"is not available"<<endl;

        }
        else{
            sum+=it->second;//累计学分

            courses.erase(it);//将刚才选过的课程从map 中删除

            n--;

        }


    }cout<<"total credit"<<sum<<endl;
    return 0;
    


}



