//链表
#include<iostream>
#include<cstdio>
#include<string.h>
//#include<malloc.h>

using namespace std;
typedef char ElemType;
typedef struct LNode//单向链表节点定义

{
    ElemType data;
    struct LNode * next;

}LinkList;

void CreateListH(LinkList *&L,ElemType a[],int n);//头插法
void CreateLsitT(LinkList *&L,ElemType a[],int n);//尾插法
void InitList(LinkList *&L);//初始化链表
void DestroyList( LinkList *&L);//销毁链表
int ListIsEmpty(LinkList *L);
int ListLength(LinkList *L);
void Display(LinkList *L);//输出链表
int GetELem(LinkList *L,int i,ElemType &e);
int LocationElem(LinkList *L,ElemType e);//按照元素值查找
int Insert(LinkList *&L,int i, ElemType e);//插入元素
int Delete(LinkList *&L ,int i,ElemType &e);//删除数据元素

void CreateListH(LinkList *&L,ElemType a[],int n)
{
    LinkList *s;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));//创建链表L，并为其分配内存
    L->next=NULL;
    for(i=0;i<n;i++)//循环创建数据节点*S
    {
        s=(LinkList *)malloc(sizeof(LinkList));//动态为S分配内存
        s->data=a[i];
        s->next=L->next;
        L->next=s;

    }


}
void CreateListT(LinkList *&L,ElemType a[],int n)
{
    LinkList *s,*r;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));
    r=L;//r始终指向尾节点，开始是指向头节点
    for(i=0;i<n;i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=a[i];
        r->next=s;
        r=s;

    }
    r->next=NULL;//尾节点设置为null;



}
void InitList(LinkList *&L)//初始化链表
{
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;

}

void DestroyList( LinkList *&L)
{
    LinkList *p=L,*q=p->next;//p指向q 的前驱
    while(q!=NULL)//扫描单链表
    {
        free(q);
        p=q;
        q=p->next;



    }
    free(p);//循环结束时，q=null ,p指向尾巴节点，释放


}
int ListIsEmpty(LinkList *L){
    return (L->next==NULL);

}
int ListLength(LinkList *L)
{
    LinkList *p=L;
    int n=0;
    while(p->next!=NULL)
    {
        n++;
        p=p->next;

    }
    return n;//循环结束 p指向尾巴节点，n 为节点个数

}
void Display(LinkList *L)
{
    LinkList *p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;

    }
}

int GetELem(LinkList *L,int i,ElemType &e){
    int j=0;
    LinkList *p=L;
    while(j<i&&p!=NULL)
    {
        j++;
        p=p->next;

    }
    if(p==NULL)//不存在i；
        return 0;
    else
    {
        e=p->data;
        return 1;

    }
}
int LocationElem(LinkList *L,ElemType e)//按照元素值查找
{
    LinkList *p=L->next;//p指向开始的节点
    int i=1;
    while(p!=NULL&&p->data!=e)

    {
        p=p->next;
        i++;


    }
    if(p==NULL)
        return 0;
    else
        return (i);


}
int Insert(LinkList *&L,int i ,ElemType e)//在位置i插入元素
{
    int j=0;
    LinkList *p=L,*s;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;

    }
    if(p==NULL)return 0;//为找到位置i-1
    else
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=e;
        s->next=p->next;
        p->next=s;
        //把*s 插入到*p 之后
        return 1;


    }






}
int Delete(LinkList *&L ,int i,ElemType &e)//删除位置i 的数据元素
{
    int j=0;
    LinkList *p=L,*q;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;

    }
    if(p==NULL)//未找到第i-1个节点
        return 0;
    else
    {
        q=p->next;
        if(q==NULL)
            return 0;
        e=q->data;
        p->next=q->next;
        free(q);
        return 1;


    }

}

int main(){
    ElemType e,a[5]={'a','b','c','d','f'};
    LinkList *h;
    InitList(h);
    CreateLsitT(h,a,5);
    cout<<"单链表为："<<endl;
    Display(h);


}




