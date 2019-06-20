#include<iostream>
#include<stdio.h>
#include<cstdio>
#include <cstring>
#include<vector>
#include<iterator>
#include<algorithm>
#include<exception>
#include<stack>
#include<deque>
#include<cmath>

using namespace std;
//deque 容器 两端队列

/*
 * 相比于vector deque是双口，可以在两端插入和删除，
 * front（）/back（）：返回的是元素
 * begin（）/end():返回的是迭代器
 * 常有的API
 */
//初始化
//void test1(){
//    deque<int >d1;
//    deque<int >d2(10,5);
//    deque<int >d3(d2.begin(),d2.end());
//    deque<int >d4(d3);
//    d4.push_back(100);
//    d4.push_front(100);
//
//
//
//    for(deque<int >::iterator it=d4.begin();it!=d4.end();it++)
//    {
//        cout<<*it<<" ";
//
//    }
//    cout<<endl;
//
//
//
//}
//
//
//
//
//
//
//int main(){
//    test1();
//    return 0;
//
//}

//评委打分案例
//创建5个选手，10个评委对5个选手进行打分
//得分规则是：去掉最高和最低，取平均分
//按照得分对5名选手进行排名


class Player{
public:
    //Player(string  name,int score){this->mName=name;this->mScore=score;}
    Player(string name,int score):mName(name),mScore(score){}
public:
    string  mName;
    int mScore;
};
//创建选手
void CreatePlayer(vector<Player>& v){
    string nameSeed="ABCDE";
    for(int i=0;i<5;i++){
        Player p;
        p.mName="选手";
        p.mName+=nameSeed[i];
        p.mScore=0;
        v.push_back(p);

    }



}
//打分

void Set_score(vector<Player>&v){
    for(vector<Player>::iterator it=v.begin();it!=v.end();it++)//遍历选手

    {//打分
        deque<int>dScore;


        for(int i=0;i<10;i++)
        {
            int score=rand() %41+60;//[60,100)
            dScore.push_back(score);

        }
        //对分数排序,调用ALg.默认使用的是从小到大
        sort(dScore.begin(),dScore.end());
        //去除最高分和最低分

        dScore.pop_back();
        dScore.pop_front();

        //求平jun分
        int sumScore=0;
        for(deque<int>::iterator dit=dScore.begin();dit!=dScore.end();dit++)
        {
            sumScore+=(*dit);

        }
        int avg=sumScore/dScore.size();

        //保存分数
        (*it).mScore=avg;



    }
}



//根据分数排序
void PrintRank(vector<Player>&v)
{

    sort(v.begin(),v.end());
    for(vector<Player>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"姓名：  "<<(*it).mName<<"得分"<<(*it).mScore<<endl;

    }

}

int main(){
    vector<Player> vPlist;

    CreatePlayer(vPlist);
    Set_score(vPlist);
    PrintRank(vPlist);


    return 0;
}





