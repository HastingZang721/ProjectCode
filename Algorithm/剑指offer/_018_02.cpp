#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

#include<cmath>

using namespace std;
//删除链表中重复的节点
typedef char ElemType;
 struct LNode//单向链表节点定义

{
    ElemType data;
    struct LNode * next;
    LNode(int x=0):data(x),next(NULL){}

};

//class SOlution{
//public :
//    LNode* deleteDUplication(LNode* pHead)
//    {
//    LNode* first=new LNode(-1);//设置头指针first
//    first->next=pHead;
//    LNode *p=pHead;
//    LNode *last=first;
//    while(p!=NULL&&p->next!=NULL)//当前的节点的前一个节点（last）与后面值比当前节点大的节点仍然需要相连
//        cout<<p->data<<" ";
//    if(p->data==p->next->data)//若有节点重复，则跳过所有重复的节点
//    {
//        int val = p->data;//记录下data值
//        while (p != NULL && p->data == val) {
//            p = p->next;//跳过所有重复的数字
//
//        }
//        //此时p指向的是后遇到的第一个非重复数字
//        last->next = p;//将last与p相联系
//    }
//    else
//        //没有遇到重复的数字情况下
//    {
//        last=p;
//        p=p->next;
//
//    }
//
//
//    return first->next;
//
//
//}
//
//
//};

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#ifdef  __tmain

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x = 0)
            :
            val(x), next(NULL) {
    }
};
#endif //   __tmain


class Solution
{
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        //设置一个trick, 作为头指针, 这样我们无需单独考虑第一个元素
        ListNode *first = new ListNode(-1);

        first->next = pHead;

        ListNode *p = pHead;
        ListNode *last = first;

        while (p != NULL && p->next != NULL)
        {
            debug <<p->val <<endl;

            //  如果有元素重复
            if (p->val == p->next->val)
            {
                //  就跳过所有重复的数字
                int val = p->val;
                while (p != NULL && p->val == val)
                {
                    p = p->next;
                }

                //  此时p指向了非重复的第一个元素
                //  我们设置last->next = p
                //  但是此时p-val也可能是重复的,
                //  因此我们不可以设置last = p
                //  而是重新进入循环
                last->next = p;
            }
            else
            {
                last = p;
                p = p->next;
            }
        }
        return first->next;
    }
};



int __tmain( )
{
    Solution solu;

    ListNode list[7];

    list[0].val = 1;
    list[0].next = &list[1];

    list[1].val = 2;
    list[1].next = &list[2];

    list[2].val = 3;
    list[2].next = &list[3];

    list[3].val = 3;
    list[3].next = &list[4];

    list[4].val = 4;
    list[4].next = &list[5];

    list[5].val = 4;
    list[5].next = &list[6];

    list[6].val = 5;
    list[6].next = NULL;


    ListNode *node = solu.deleteDuplication(list);

    while(node != NULL)
    {
        cout <<node->val <<" -=> ";
        node = node->next;
    }
    return 0;
