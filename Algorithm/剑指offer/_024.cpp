#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>


using namespace std;
//反转链表
//解法1 三指针反转


struct ListNode {
    int m_nValue;
    ListNode *m_pNext;

};

ListNode *ReverseList(ListNode *pHead) {
    ListNode *pReverseHead = nullptr;//标记反转后的头节点
    ListNode *pNode = pHead;
    ListNode *pPrev = nullptr;
    while (pNode != nullptr) {
        ListNode *pNext = pNode->m_pNext;//一直遍历到链表尾部
        if (pNext == nullptr)
            pReverseHead = pNode;
        pNode->m_pNext = pPrev;//反转每个节点
        pPrev = pNode;//保存前一个指针
        pNode = pNext;


    }
    return pReverseHead;
}

//解法2
//遍历链表后，将每个元素头插入新链表
class Solution {
public :
    ListNode *ReverseList2(ListNode *phead) {
        if (phead == nullptr) {
            return nullptr;
        }
        ListNode *pNode=phead;
        ListNode *nNode= nullptr;
        ListNode* pNext= nullptr;

        nNode=pNode;//保存链表原先的第一个节点(由于链表不带头节点，因此第一个元素的插入需要特殊处理)
        pNode=pNode->m_pNext;
        nNode->m_pNext=NULL;
        cout<<nNode->m_nValue<<"in list head now"<<endl;
        while(pNode!= nullptr)
        {
            pNext=pNode->m_pNext;//保存next指针
            //将pNode插入到nNode 的头部；
            pNode->m_pNext=nNode;
            nNode=pNode;

            cout<<nNode->m_nValue<<"in list head now"<<endl;
            pNode=pNext;//移动指针



        }

    }
};

int main() {
    ListNode list[6];
    list[0].m_nValue = 1;
    list[0].m_pNext = &list[1];
    list[1].m_nValue = 2;
    list[1].m_pNext = &list[2];
    list[2].m_nValue = 3;
    list[2].m_pNext = &list[3];
    list[3].m_nValue = 4;
    list[3].m_pNext = &list[4];
    list[4].m_nValue = 5;
    list[4].m_pNext = &list[5];
    list[5].m_nValue = 6;

    list[5].m_pNext =NULL;


    ListNode *node = list;
    while (node != nullptr) {
        cout << node->m_nValue;
        node = node->m_pNext;

    }
    cout<<endl;

//    ListNode *p = ReverseList(list);
//    cout << "After Reverse" << endl;
Solution solu;

ListNode *p=solu.ReverseList2(list);

    while (p != nullptr) {
        cout << p->m_nValue;
        p = p->m_pNext;


    }
    cout << endl;


    return 0;
}


