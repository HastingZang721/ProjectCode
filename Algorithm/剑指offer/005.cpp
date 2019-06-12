#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

typedef int ElemType;

typedef struct ListNode

{
    ElemType  m_nKey;
    ListNode*m_pNext;

}LinkList;
 void PrintLinkListReverse(LinkList *L) {
     std::stack<LinkList *> nodes;
     LinkList *p = L;//p指向头节点
     while (p != NULL) {
         nodes.push(p);//利用棧的后近先出
         p = p->m_pNext;


     }
     while (!nodes.empty())
     {
         p=nodes.top();
         cout<<p->m_nKey<<" ";
         nodes.pop();



     }

 }
void PrintList(LinkList *L)
{
     LinkList *p=L;//p指向头节点
     while(p!=NULL)
     {
         cout<<p->m_nKey<<" ";
         p=p->m_pNext;

     }

}

//============测试=================
void Test(LinkList* L)
{
    cout<<"原先的list 为："<<endl;
     PrintList(L);
     cout<<endl;
    cout<<"反向输出的list 为："<<endl;
     PrintLinkListReverse(L);
     cout<<endl;


}
void Test1()
{
     cout<<"Test1 begins: "<<endl;
     ListNode list[3];
     list[0].m_nKey=1;
     list[0].m_pNext=&list[1];
     list[1].m_nKey=2;
     list[1].m_pNext=&list[2];
     list[2].m_nKey=4;
     list[2].m_pNext=NULL;


     Test(list);


}

int main(){
     Test1();
     return 0;

 }
