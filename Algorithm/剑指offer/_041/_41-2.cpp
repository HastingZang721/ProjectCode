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


#include<cstdlib>

#define Random(x) rand()%x

#include <time.h>

using namespace std;

/*
 *数据流中的中位数
 * 数值可能会不断增加
 * 1：若是没有排序的数组中，则使用第39题的方法调用partition函数来查找
 * 2：若是在两个已排序的数组中查找中位数（见41——1.cpp）
 * 3:若是在排序的链表中使用两指针求中位数（见41-2。cpp）
 * 4:使用最大堆和最小堆来实现（见41-3。cpp）
 *
 */

//若是在排序的链表中使用两指针求中位数（见41-2。cpp）
//使用快慢指针的方式，当快指针走到尾部的时候，慢指针正好走到中间

struct LinkNode{
    int data;
    LinkNode* next;

};
//创建链表(头插法)简单便捷但插入的数据与插入的顺序相反；
void CreateLinkH(LinkNode *&L,int a[],int n)
{
    LinkNode *s;
    int i;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
    //循环创建节点
    for(i=0;i<n;i++) {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }


}

//尾部插入法
void CreateListT(LinkNode*&L,int a[],int n)
{
    LinkNode *s,*r;
    int i;
    L=(LinkNode*)malloc(sizeof(LinkNode));
    L->next=NULL;
    r=L;

    for(i=0;i<n;i++)
    {
        s=(LinkNode*)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;
        r=s;

    }
    r->next=NULL;
}


//初始化链表
void InitialList(LinkNode*&L)
{
    L=(LinkNode*)malloc(sizeof(LinkNode));
    L->next=NULL;

}

//打印链表
void Display(LinkNode*L)
{
    LinkNode *p=L;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}


void DestroyList(LinkNode*&L)
{
    LinkNode*p=L,*q=p->next;
    while(q!=NULL)
    {
        free(q);
        p=q;
        q=p->next;
    }
    free(p);

}

//快慢指针找中位数
void FindMiddle(LinkNode *L)
{
    LinkNode *mid,*faster;
    mid=L->next;
    faster=L->next;
    while(faster!=NULL)
    {
        mid=mid->next;
        faster=faster->next->next;

    }
    cout<<mid->data<<endl;
}

int main()
{
    int a[]={1,3,5,7,9,12,14,16,18,19};
    LinkNode *H;
    InitialList(H);
    CreateListT(H,a,10);
    cout<<"单链表为：";

    Display(H);
    cout<<"中位数：";
    FindMiddle(H);


}