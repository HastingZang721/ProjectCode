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
#include <math>

#include <string>


using namespace std;

/*
 * 两个链表的第一个公共节点
 *
 * 思路2：使用两个辅助棧来分别存放两个单链表的节点
 * 思路三：先分别遍历两个节点的长度，然后让那长的节点多走，接着在同时遍历两个链表
 *
 *
 */

struct ListNode {
    int data;
    ListNode *next;

};

ListNode *temp=NULL;

//思路2；
class solution2 {
public:


    ListNode *FindFirstCommonNode(!s1.empty()&&!s2.empty())
    {

        temp=s1.top();
        s1.pop();
        s2.pop();
        if(s1.top()!=s2.top())
        {
            break;
        }
        return temp;

    }


    void pushintostack(ListNode *p1)
    {
        while(p1->next!=NULL)
        {
            s1.push(p1->data);
            p1=p1->next;

        }
    }
public:
    stack<int> s1;
    stack<int> s2;
};





class SOlution3{
public:
    int GetLength(ListNode* pHead)
    {
        int length=0;
        ListNode *p=pHead;
        while(p!= nullptr)
        {
            ++length;
            p=p->next;

        }

        return length;
    }

    ListNode* FistrCOmmonNode(ListNode* pHead1,ListNode* pHead2)

    {
        unsigned int len1=GetLength(pHead1);
        unsigned int len2=GetLength(pHead2);

        int DiffLen=abs(len1-len2);
        
        ListNode* pLong=pHead1;
        ListNode* pShort=pHead2;
        if(len2>len1)
        {
            pLong=pHead2;
            pLong=pHead1;
            DiffLen=len2-len1;
        }
        
        //先在长链表上多走几步
        for(int i=0;i<DiffLen;++i)
        {
            pLong=pLong->next;
            
        }
        //同步遍历两链表
        while(pLong!=NULL&&pShort!=NULL&&pLong!=pShort)
        
        {
            pLong=pLong->next;
            pShort=pShort->next;
            
        }
        ListNode* FirstCOmmonNode=pLong;
        return  FirstCOmmonNode;
    }
};